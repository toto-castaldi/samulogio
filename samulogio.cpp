int Get_Centerpoint(int target, int max_target, int nElements, int offset)
{
	//example: 
	//which light should I turn on if it is 6 PM?
	//target: 6
	//max_target: 12 [we want a base 12 clock]
	//nElements: 24  [we have a 24 led ring]
	//offset: -2     [we should move our zero light is 2 leds counterclockwise]

		while (offset<0)
			offset+=nElements;
			
		int answ = (target * nElements)/max_target;
		answ+=offset;
		return answ % nElements;
}

int Get_Slug(int target, int max_target, int nElements, int offset)
{
	//example: 
	//which light should I turn on if it is 6 PM?
	//target: 6
	//max_target: 12 [we want a base 12 clock]
	//nElements: 24  [we have a 24 led ring]
	//offset: -2     [we should move our zero light is 2 leds counterclockwise]

		while (offset<0)
			offset+=nElements;
			
		int answ = (target * nElements)/max_target;
		answ+=offset;
		return answ % nElements;
}		
		
