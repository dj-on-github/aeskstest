#include <stdio.h>

extern void aesni128k128d(unsigned char *key, unsigned char *data, unsigned char *ciphertext);
extern void aessw128k128d(unsigned char *key, unsigned char *data, unsigned char *ciphertext);

int aesni_supported;

void printsample(unsigned char *thesample)
{
    int i;
    for (i=0;i<16;i++) printf("%02X",thesample[i]);
    printf("\n");
}

int main() {

    unsigned char key[16];
    unsigned char data[16];
    unsigned char ciphertext[16];

    int i;

    key[0 ] = 0x3c;
    key[1 ] = 0x4f;
    key[2 ] = 0xcf;
    key[3 ] = 0x09;
    key[4 ] = 0x88;
    key[5 ] = 0x15;
    key[6 ] = 0xf7;
    key[7 ] = 0xab;
    key[8 ] = 0xa6;
    key[9 ] = 0xd2;
    key[10] = 0xae;
    key[11] = 0x28;
    key[12] = 0x16;
    key[13] = 0x15;
    key[14] = 0x7e;
    key[15] = 0x2b;


    for(i=0;i<16;i++) {
        data[i]=0x00;
        ciphertext[i]=0x00;
    }

    //key[15]=0x01;
    data[15]=0x10;

    aesni128k128d(key,data,ciphertext);
    //printsample(ciphertext);

    aessw128k128d(key,data,ciphertext);
    //printsample(ciphertext);

}
