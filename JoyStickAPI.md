JoyStickAPI Documentation

__________________________________________

Join Header #include 'JoyStick.h

Join Lib to Project (DevC++ libxinput_1.4.a)

Visual Studio #pragma comment('xinput_1.4.lib'');

JoyStickAPI* xController1; - add to Controller 1

JoyStickAPI* xController2; - add to Controller 2

xController1 = new JoyStickAPI(1); - call to Controller 1

xController2 = new JoyStickAPI(2); - call to Controller 2

if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) - Check btn

{

return 1;

}

xController1->GetState().Gamepad.sThumbLX // return axis LeftX

xController1->GetState().Gamepad.sThumbLY // return axis LeftY

xController1->GetState().Gamepad.sThumbRX // return axis RightX

xController1->GetState().Gamepad.sThumbRY // return axis RightY

xController1->GetState().Gamepad.bLeftTrigger // return LT range or 0 to 255

xController1->GetState().Gamepad.bRightTrigger //return RT range or 0 to 255

if(xController1->IsConnected()) - check connection controller if connected to return true else false

Please Check My Site

by HCPP

Open Site
