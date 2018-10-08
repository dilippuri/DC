struct gcdin{
	int x;
	int y;
};
struct gcdout{
	int z;
};
program GCD_P{
	version GCD_V{
		gcdout GCD(gcdin) = 1;
	}=1;
}= 0x3434001;
