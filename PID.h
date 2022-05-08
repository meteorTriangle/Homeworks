//u(t)=u(t-1)+Kp[e(t)-e(t-1)]+Ki[e(t)]+Kd[e(t)-2e(t-1)+e(t-2)]
class PID{
  private:
    double Kp, Ki, Kd;
    double output, lastOutput = 0;
    double et0 = 0, et1 = 0, et2 = 0;
  public:
    void init(double, double, double);
    double PIDv1(double ,double);
};

void PID::init(double p, double i, double d){
  Kp = p;
  Ki = i;
  Kd = d;
}

double PID::PIDv1(double setpoint, double process){
  et0 = setpoint - process;
  output = lastOutput + (Kp*(et0 - et1)) + (Ki*(et0)) - (Kd*(et0 - (2*et1) + et2));
  et2 = et1;
  et1 = et0;
  if(output > 65535){
    output = 65535;
  }
  if(output < -65535){
    output = -65535;
  }
  lastOutput = output;
  return(output);
}
