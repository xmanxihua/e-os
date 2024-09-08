//#define UFCON0  ((volatile unsigned int *)(0x50000020))
//typedef unsigned int uint32_t;
//typedef unsigned char uint8_t;
//typedef volatile struct {
//	uint32_t DR;
//	uint32_t RSR_ECR;
//	uint8_t reserved1[0x10];
//	const uint32_t FR;
//	uint8_t reserved2[0x4];
//	uint32_t LPR;
//	uint32_t IBRD;
//	uint32_t FBRD;
//	uint32_t LCR_H;
//	uint32_t CR;
//	uint32_t IFLS;
//	uint32_t IMSC;
//	const uint32_t RIS;
//	const uint32_t MIS;
//	uint32_t ICR;
//	uint32_t DMACR;
//} pl011_t;

//enum {
//	RXFE = 0x10,
//	TXFF = 0x20,
//};
#define UFCON0  ((volatile unsigned int *)(0x10009000))
//volatile pl011_t* const UART0 = (pl011_t*)UFCON0;
void helloworld(void){
    //while(UART0->FR & TXFF);

    char *p="helloworld\n";
    while(*p){
        *UFCON0=*p++;
    };
    while(1);
}
