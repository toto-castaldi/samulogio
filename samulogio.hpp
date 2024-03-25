//the following int constants must be defined
// R1: size of the 1st ring
// R2: size of the 2nd ring
// R3: size of the 3rd ring

//If your configuration uses 12, 24 and 60 leds, depending on your wiring, you can define one of the following 
// SML, SLM, MSL, MLS, LSM, LMS
// SML means Small -> Medium -> Large
#include <bitset>
#include <utility>
#define SML
namespace samulogio
{
#ifdef SML
	//small	->	mid	->	large
	const int R1 = 12, R2 = 24, R3 = 60;				
			
#endif
#ifdef SLM
	//small	->	large	->	mid
    const int R1 = 12, R2 = 60, R3 = 24;							
#endif
#ifdef MSL
	//mid	->	small	->	large
	const int R1 = 24, R2 = 12, R3 = 60;				
#endif
#ifdef MLS
	//mid	->	large	->	small
	const int R1 = 24, R2 = 60, R3 = 12;				
#endif
#ifdef LSM
	//large	->	small	->	mid
	const int R1 = 60, R2 = 12, R3 = 24;				
#endif
#ifdef LMS
	//large	->	mid	->	small
	const int R1 = 60, R2 = 24, R3 = 12;				
#endif
 

const int START_SMALL = 0;				
const int START_MID = R1;
const int START_LARGE = R1 + R2;				

//const int end_small = R1 - 1;				
//const int end_mid = R1 + R2 -1;				
//const int end_large = R1 + R2 + R3 -1;	

const int OFFSET_R1 = +3;
const int OFFSET_R2 = -3;
const int OFFSET_R3 = 30;

}

int Get_Centerpoint(int target, int max_target, int nElements, int offset, int indexOfLed0)
{
    //example: 
    //which light should I turn on if it is 6 PM?
    //target: 6
    //max_target: 12 [we want a base 12 clock]
    //nElements: 24  [we have a 24 led ring]
    //offset: -2     [we should move our zero light is 2 leds counterclockwise]
	//indexOfLed0 11
    //it should return 25
	
	target = target % max_target;
	while (target < 0)
		target +=max_target;

	int answ = (target * nElements)/max_target;
	answ-=offset;
	answ=answ % nElements;
	while (answ<0)
		answ+=nElements;
	answ+=indexOfLed0;
	return answ;
}


//first can be higher than last
std::pair<int,int> GetFirstAndLastIndex(int target, int max_target, int nElements, int offset, int indexOfLed0, int ledBefore, int ledAfter)
{
	//Example 1: It's 1 PM. I want the list of lights which are 6 led before and 3 led after 1 PM
    //Led 0 is "two leds to the left"
    //I have a 24 led clock, hours goes up to 12.
    //GetFirstAndLastIndex(1, 12, 24, -2, 6, 3) should return
	//Should return -3
	//edge case "noon/00"
	std::pair<int,int> myAnsw;
	if (ledBefore < 0) ledBefore *= -1;
    if (ledAfter < 0) ledAfter *= -1;
    ledBefore = ledBefore % nElements;
    ledAfter = ledAfter % nElements;
    int cP = Get_Centerpoint(target, max_target, nElements, offset, indexOfLed0);    //4
    myAnsw.first = (cP - ledBefore) % nElements;
	myAnsw.second = (cP + ledAfter) % nElements;
	
	while (myAnsw.first < 0) myAnsw.first+=nElements;
	while (myAnsw.second < 0) myAnsw.second+=nElements;
	return myAnsw;
}
std::pair<int,int> GetFirstAndLastTime(int target, int max_target, int nElements, int offset, int indexOfLed0, int deltaBefore, int deltaAfter)
{
	//similar to previous, but using time instead of number of leds 
	std::pair<int,int> myAnsw;
	if (deltaBefore < 0) deltaBefore *= -1;
    if (deltaAfter < 0) deltaAfter *= -1;
    
    myAnsw.first = Get_Centerpoint(target - deltaBefore, max_target, nElements, offset, indexOfLed0);    //4
	myAnsw.second = Get_Centerpoint(target - deltaBefore, max_target, nElements, offset, indexOfLed0);
	
	return myAnsw;
}

