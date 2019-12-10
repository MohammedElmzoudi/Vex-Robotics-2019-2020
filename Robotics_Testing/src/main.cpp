/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       abdelkebirelmzoudi                                        */
/*    Created:      Thu Oct 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instanece of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here
vex::motor left_motor (vex::PORT2,vex::gearSetting::ratio18_1,false);
vex::motor right_motor (vex::PORT1,vex::gearSetting::ratio18_1,false);
vex::motor intake_lift2 (vex::PORT3,vex::gearSetting::ratio18_1,false);
vex::motor intake_lift1 (vex::PORT4,vex::gearSetting::ratio18_1,false);
vex::motor right_intake (vex::PORT5,vex::gearSetting::ratio18_1,false);
vex::motor left_intake (vex::PORT6,vex::gearSetting::ratio18_1,false);
vex::motor arm_push (vex::PORT7,vex::gearSetting::ratio18_1,false);
vex::controller cont = vex::controller();

int main() {

    while(1) 
    {
      // Spin motors with velocity = to joystick axis values
      if( cont.Axis1.value()!= 0 || cont.Axis2.value()!=0 || cont.Axis3.value()!=0 || cont.Axis4.value()!=0 )
      {
        right_motor.spin(vex::directionType::rev, (cont.Axis3.value()*2.5 - cont.Axis4.value())*(1), velocityUnits::pct);
        left_motor.spin(vex::directionType::fwd, (cont.Axis3.value()*2.5 + cont.Axis4.value())*(1), velocityUnits::pct);
      }
       else 
       {
         right_motor.stop();
         left_motor.stop();
       }

      if(cont.ButtonX.pressing())
       {
          right_intake.spin(vex::directionType::fwd,300, velocityUnits::pct );
          left_intake.spin(vex::directionType::rev,300, velocityUnits::pct );
       }
       else if(cont.ButtonB.pressing())
       {
          right_intake.spin(vex::directionType::rev,50, velocityUnits::pct );
          left_intake.spin(vex::directionType::fwd,50, velocityUnits::pct );
       }
       else 
       {
         right_intake.stop(brakeType::brake);
         left_intake.stop(brakeType::brake);
       }

       if(cont.ButtonR1.pressing())
       {
         intake_lift1.spin(vex::directionType::fwd,30, velocityUnits::pct );
         intake_lift2.spin(vex::directionType::rev,30, velocityUnits::pct );
       }
       else if(cont.ButtonR2.pressing())
       {
         intake_lift1.spin(vex::directionType::rev,20, velocityUnits::pct );
         intake_lift2.spin(vex::directionType::fwd,20, velocityUnits::pct );
       }
       else 
       {
         intake_lift1.stop(brakeType::brake);
         intake_lift2.stop(brakeType::brake);
       }
      
      if( cont.ButtonL1.pressing() )
      {
        arm_push.spin(vex::directionType::fwd,5,velocityUnits::pct );
      }
      else if(cont.ButtonL2.pressing())
      {
        arm_push.spin(vex::directionType::fwd,-5,velocityUnits::pct );
      }
      else
      {
        
        arm_push.stop(brakeType::brake);
      }
       vex::this_thread::sleep_for(1);
    }
}

