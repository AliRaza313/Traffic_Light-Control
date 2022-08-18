/*This code implements the traffic light system for a quad way intersection.
  Note that the Phases A,B,C and D in the figure 1 of the task are assigned
  integers 1,2,3 and 4 respectively here in code.
*/

//Folowing variables are for storing the information of current and Next phase of the Traffic System
int Current_Phase;
int Next_Phase;

//The folowing three integer variables are used for LED control in the Light_Transition function 
int Red_Light,Yellow_Light,Green_Light;

//This is a multidimentional array is used for addressing the pins with which the LEDs of a specific phase are connected 
int light_Adress_Array [4][4] = { { 1, 2, 3,4 }, { 2, 5, 6,7 } , { 3, 8, 9,10 }, { 4, 11, 12,13} };


void setup() {
  
// declaration of Digital output Ports for LED's (emulating the traffic light), thus for each phase 3 LEDs are to be connected with the controller

//declration of LEDs for Phase 1
pinMode (2,OUTPUT);
pinMode (3,OUTPUT);
pinMode (4,OUTPUT);

//declration of LEDs for Phase 2
pinMode (5,OUTPUT);
pinMode (6,OUTPUT);
pinMode (7,OUTPUT);

//declration of LEDs for Phase 3
pinMode (8,OUTPUT);
pinMode (9,OUTPUT);
pinMode (10,OUTPUT);

//declration of LEDs for Phase 4 
pinMode (11,OUTPUT);
pinMode (12,OUTPUT);
pinMode (13,OUTPUT);

//seting the initial value of cxurrent phase to be 1 (which represents Phase A of the Figure 1) therefore, on every restart of the system Traffic Light of Phase A would starts its normal transitions and other phases would foloow.
Current_Phase = 1;

//Setting up all the red lights on to start with (This would happen on every reset).
//Red Light of Phase 1
digitalWrite (2,HIGH);

//Red Light of Phase 2
digitalWrite (5,HIGH);

//Red Light of Phase 3
digitalWrite (8,HIGH);

//Red Light of Phase 4
digitalWrite (11,HIGH);

delay (1000);
}

void loop() {
        Light_Transition(Current_Phase);
        Phase_Select(Current_Phase);
        Current_Phase = Next_Phase;
}

/*
  *This Function implements the Traffic light transition control as per the desired timing requirements.
  *The control is implemented withrespect to the Phase input gien to the function as argument.
  *Therefore, if Phase is equal to 1 the contrl woudl be implemented for the LEDs emulating the traffic light of phase A of intersection (1 in code)
  
  *Note that delay command is used in thid fucntion in place of other timing control methods, although this usage is not very much recomended however in the given design
  the requirment was as such that use of delay fucntion became inevitable as the transitions in the design takes place in series and hence one step has to finish to allow
  other step to continue.
 */
void Light_Transition ( int Phase)
{ 
    // The addressing of pins for transition of Phase lights are carried out here with help of a multi dimentional array, This array has 4 rows (representing 4 phases), The adress of puns lie in the columns of array against each pahse.
    Red_Light = light_Adress_Array[Phase -1][1] ;
    Yellow_Light = light_Adress_Array[Phase -1][2] ;
    Green_Light = light_Adress_Array[Phase -1][3] ;  

   //Light transition control
   
   digitalWrite(Red_Light,LOW);
   
   digitalWrite(Yellow_Light,HIGH);
   //delay of 2 seconds, as per design requirements 
   delay (2000);
   digitalWrite(Yellow_Light,LOW);
   digitalWrite(Green_Light,HIGH);
   //delay of 30 seconds, as per design requirements 
   delay (30000);
   digitalWrite(Green_Light,LOW);
   digitalWrite(Yellow_Light,HIGH);
   //delay of 30 seconds, as per design requirements 
   delay (5000);   
   digitalWrite(Yellow_Light,LOW);   
   digitalWrite(Red_Light,HIGH);
  
  }


/*
  This function implements the next phase decision functionality based on the current phase, given to it as argument.
 */
void Phase_Select (int current_Phase)
{
   Next_Phase = current_Phase + 1;
   if (Next_Phase == 5)
   {
    Next_Phase = 1;
    }
  }

