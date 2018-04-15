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
	using Lap_Data_Size = unsigned int;
	using Lap_Pos = unsigned int;

	virtual ~Decision() {}

	virtual void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) = 0;

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

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_On_Road_FL : public Absolute {
public:
	virtual ~Absolute_On_Road_FL() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_On_Road_FR : public Absolute {
public:
	virtual ~Absolute_On_Road_FR() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};


class Absolute_On_Road_RL : public Absolute {
public:
	virtual ~Absolute_On_Road_RL() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};


class Absolute_On_Road_RR : public Absolute {
public:
	virtual ~Absolute_On_Road_RR() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};


class Absolute_Brake_GT : public Absolute {
public:
	using Brake = unsigned int;

	Absolute_Brake_GT(const Brake = 0);
	virtual ~Absolute_Brake_GT() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Brake brake_;
};

class Absolute_Gear : public Absolute {
public:
	using Gear = unsigned int;

	Absolute_Gear(const Gear);
	virtual ~Absolute_Gear() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
private:
	Gear gear_;
};

class Absolute_Top_Gear : public Absolute {
public:
	virtual ~Absolute_Top_Gear() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_2_Tyres_On_Road : public Absolute {
public:
	virtual ~Absolute_2_Tyres_On_Road() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_Steering_Straight : public Absolute {
public:
	virtual ~Absolute_Steering_Straight() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_Full_Throttle : public Absolute {
public:
	virtual ~Absolute_Full_Throttle() {}

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;
};

class Absolute_Turn_Left_Between : public Absolute {
public:
	using Percent_GT = int;
	using Percent_LT = int;

	Absolute_Turn_Left_Between(const Percent_GT&, const Percent_LT&);
	virtual ~Absolute_Turn_Left_Between() {} 

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Percent_GT percent_gt_;
	Percent_LT percent_lt_;
};

class Absolute_Turn_Right_Between : public Absolute {
public:
	using Percent_GT = int;
	using Percent_LT = int;

	Absolute_Turn_Right_Between(const Percent_GT&, const Percent_LT&);
	virtual ~Absolute_Turn_Right_Between() {} 

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Percent_GT percent_gt_;
	Percent_LT percent_lt_;
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

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	bool result_;
	Conclusion_Ptr conclusion_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_RPM_GT_Percent : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Percent = unsigned int; 

	Decision_RPM_GT_Percent(Conclusion_Ptr, const Percent);
	virtual ~Decision_RPM_GT_Percent() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	bool result_;
	Conclusion_Ptr conclusion_;
	Percent percent_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_Percent_Per_Lap : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Count = unsigned int;
	using Percent_Throttle = double;

	Decision_Percent_Per_Lap(Conclusion_Ptr);
	virtual ~Decision_Percent_Per_Lap() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Count count_;
	Percent_Throttle percent_;

	Conclusion_Ptr conclusion_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MAX_Tyre_Temp : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Temp = unsigned int;

	Decision_MAX_Tyre_Temp(Conclusion_Ptr);
	virtual ~Decision_MAX_Tyre_Temp() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Temp fl_temp_;
	Temp fr_temp_;
	Temp rl_temp_;
	Temp rr_temp_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MAX_Tyre_Slip_Speed : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Slip_Speed = float;

	Decision_MAX_Tyre_Slip_Speed(Conclusion_Ptr);
	virtual ~Decision_MAX_Tyre_Slip_Speed() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Slip_Speed fl_slip_speed_;
	Slip_Speed fr_slip_speed_;
	Slip_Speed rl_slip_speed_;
	Slip_Speed rr_slip_speed_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};


class Decision_MAX_Brake_Temp : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Temp = int;

	Decision_MAX_Brake_Temp(Conclusion_Ptr);
	virtual ~Decision_MAX_Brake_Temp() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Temp fl_temp_;
	Temp fr_temp_;
	Temp rl_temp_;
	Temp rr_temp_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};


class Decision_MAX_Tyre_Layer_Temp : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Temp = unsigned int;

	Decision_MAX_Tyre_Layer_Temp(Conclusion_Ptr);
	virtual ~Decision_MAX_Tyre_Layer_Temp() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Temp fl_temp_;
	Temp fr_temp_;
	Temp rl_temp_;
	Temp rr_temp_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};


class Decision_MAX_Speed : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Speed = float;

	Decision_MAX_Speed(Conclusion_Ptr);
	virtual ~Decision_MAX_Speed() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Speed speed_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MIN_FL_Ride_Height : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Height = float;

	Decision_MIN_FL_Ride_Height(Conclusion_Ptr);
	virtual ~Decision_MIN_FL_Ride_Height() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Height height_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MIN_FR_Ride_Height : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Height = float;

	Decision_MIN_FR_Ride_Height(Conclusion_Ptr);
	virtual ~Decision_MIN_FR_Ride_Height() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Height height_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MIN_RL_Ride_Height : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Height = float;

	Decision_MIN_RL_Ride_Height(Conclusion_Ptr);
	virtual ~Decision_MIN_RL_Ride_Height() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Height height_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_MIN_RR_Ride_Height : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Height = float;

	Decision_MIN_RR_Ride_Height(Conclusion_Ptr);
	virtual ~Decision_MIN_RR_Ride_Height() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;

	Height height_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};

class Decision_Lap_Time : public Decision, public Result {
public:
	using Conclusion_Ptr = std::shared_ptr<Conclusion>;
	using Lap_Time = float;

	Decision_Lap_Time(Conclusion_Ptr);
	virtual ~Decision_Lap_Time() {}

	void result() override;

	void evaluate(const Data_Shared_Ptr &, const Lap_Data_Size, const Lap_Pos) override;

private:
	Conclusion_Ptr conclusion_;
	Lap_Time lap_time_;

	void if_true(Decision_Shared_Ptr) override {};
	void if_false(Decision_Shared_Ptr) override {};
};



}


#endif

