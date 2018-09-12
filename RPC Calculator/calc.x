struct calc_in{
   int x;
   int y;
   int z;
};

program CALC_P{
	version CALC_V{
		 float calc(calc_in)=1;
	}=1;
}=0x34340000;
