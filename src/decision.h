#ifndef PCARS_DECISION_H_ 
#define PCARS_DECISION_H_ 

#include <vector>
#include <memory>

#include "data.h"

namespace pcars {

class Decision {
public:
	using Decision_Shared_Ptr = std::shared_ptr<Decision>;
	using Data_Shared_Ptr = std::shared_ptr<Data>;

	virtual ~Decision() {}

	virtual void evaluate(const Data_Shared_Ptr &) = 0;

	virtual void if_true(Decision_Shared_Ptr) = 0;
	virtual void if_false(Decision_Shared_Ptr) = 0;
};

class Absolute : public Decision {
public:
	using True_Decisions = std::vector<Decision_Shared_Ptr>;
	using False_Decisions = std::vector<Decision_Shared_Ptr>;

	virtual ~Absolute() {}

	void if_true(Decision_Shared_Ptr) override;
	void if_false(Decision_Shared_Ptr) override;

protected:
	True_Decisions true_;
	False_Decisions false_;
};

class Absolute_On_Road : public Absolute {
public:
	virtual ~Absolute_On_Road() {}

	void evaluate(const Data_Shared_Ptr &) override;
};

class Absolute_Top_Gear : public Absolute {
public:
	virtual ~Absolute_Top_Gear() {}

	void evaluate(const Data_Shared_Ptr &) override;
};

class Absolute_Steering_Straight : public Absolute {
public:
	virtual ~Absolute_Steering_Straight() {}

	void evaluate(const Data_Shared_Ptr &) override;
};

class Conclusion {
public:
	using Result_OutCome = std::string;
	virtual ~Conclusion() {}

	virtual void conclude(const Result_OutCome&) const = 0;
	virtual void conclude(const Result_OutCome&, 
	                      const Result_OutCome&,
			      const Result_OutCome&,
			      const Result_OutCome&) const = 0;
};

class Conclusion_Cout : public Conclusion {
public:
	using Outcome = std::string;

	Conclusion_Cout(const Outcome&);
	Conclusion_Cout(const Outcome&,
                        const Outcome&,
		        const Outcome&,
		        const Outcome&);
	virtual ~Conclusion_Cout() {}

	void conclude(const Result_OutCome&) const override;
	void conclude(const Result_OutCome&, 
                      const Result_OutCome&,
		      const Result_OutCome&,
		      const Result_OutCome&) const override;
private:
	Outcome outcome1_;
	Outcome outcome2_;
	Outcome outcome3_;
	Outcome outcome4_;
};


class Result {
public:
	virtual ~Result() {}

	virtual void result() = 0;
};

class Decision_MAX_RPM : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;

	Decision_MAX_RPM(Conclusion_Ptr);
	virtual ~Decision_MAX_RPM() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &) override;

private:
	bool result_;
	Conclusion_Ptr conclusion_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_RPM_GT_80_Percent : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;

	Decision_RPM_GT_80_Percent(Conclusion_Ptr);
	virtual ~Decision_RPM_GT_80_Percent() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &) override;

private:
	bool result_;
	Conclusion_Ptr conclusion_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};


class Decision_MAX_Tyre_Temp : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;

	Decision_MAX_Tyre_Temp(Conclusion_Ptr);
	virtual ~Decision_MAX_Tyre_Temp() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &) override;

private:
	Conclusion_Ptr conclusion_;

	unsigned int fl_temp_;
	unsigned int fr_temp_;
	unsigned int rl_temp_;
	unsigned int rr_temp_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};


}


#endif

