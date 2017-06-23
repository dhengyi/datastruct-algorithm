/*************************************************************************
	> File Name: MD5字符串压缩.cpp
	> Author: HowYiAlaways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年06月02日 星期五 17时24分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef unsigned long int UINT4;        //UINT4有32bit

typedef struct _MD5_CTX 
{ 
	UINT4 state[4];                 //4个链接变量
	UINT4 count[2];                 //64位二进制的原字符串长度
	unsigned char buffer[64];       //存储字符串
} MD5_CTX; 

static unsigned char PADDING[64]= {     //char[0] = 128
0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
};

//在进行四轮Hash函数变换中，s（向右环移一个不定的数）的取值
#define S11 7 
#define S12 12 
#define S13 17 
#define S14 22 
#define S21 5 
#define S22 9 
#define S23 14 
#define S24 20 
#define S31 4 
#define S32 11 
#define S33 16 
#define S34 23 
#define S41 6 
#define S42 10 
#define S43 15 
#define S44 21

//每一轮中的非线性函数（Hash函数）
#define F(x, y, z) (((x) & (y)) | ((~x) & (z))) 
#define G(x, y, z) (((x) & (z)) | ((y) & (~z))) 
#define H(x, y, z) ((x) ^ (y) ^ (z)) 
#define I(x, y, z) ((y) ^ ((x) | (~z))) 

//对x进行移位操作 
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n)))) 

/*每一轮的变换函数:
 *每次操作对a、b、c和d中的其中三个作一次非线性函数运算，然后将所得结果加上第四个变量，文本的一个子分组和一个常数。
 *再将所得结果向右环移一个不定的数，并加上a、b、c或d中之一。最后用该结果取代a、b、c或d中之一
 */
#define FF(a, b, c, d, x, s, ac) { (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define GG(a, b, c, d, x, s, ac) { (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define HH(a, b, c, d, x, s, ac) { (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define II(a, b, c, d, x, s, ac) { (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 

#define TEST_BLOCK_LEN 1000 
#define TEST_BLOCK_COUNT 1000 

class SECURITY_API CSecurity
{
public:
	//构造函数
	CSecurity(void);
	//MD5压缩加密算法
	void CSecurity :: MD5( const char *string, char *lpMD5StringBuffer ) ; 

private:
	void MD5Transform PROTO_LIST ((UINT4 [4], unsigned char [64])); 
	void MD5_memcpy PROTO_LIST ((POINTER, POINTER, size_t)); 
	void MD5_memset PROTO_LIST ((POINTER, int, size_t)); 
	void MD5Init PROTO_LIST ((MD5_CTX *)); 
	void MD5Update PROTO_LIST ((MD5_CTX *, unsigned char *, size_t)); 
	void MD5Final PROTO_LIST ((unsigned char [16], MD5_CTX *)); 
	void MDTimeTrial PROTO_LIST ((void)); 
	void StringAddOne PROTO_LIST ((char *)); 
	void Encode PROTO_LIST ((unsigned char *, UINT4 *, size_t)); 
	void Decode PROTO_LIST ((UINT4 *, unsigned char *, size_t)); 
};

void CSecurity :: MD5Init( MD5_CTX *context ) 
{ 
	context->count[0] = context -> count[1] = 0;
	context->state[0] = 0x67452301;
	context->state[1] = 0xefcdab89;
	context->state[2] = 0x98badcfe;
	context->state[3] = 0x10325476;
}

void CSecurity :: MD5Update( MD5_CTX *context, unsigned char *input, size_t inputLen) 
{ 
size_t i, index, partLen; 

/* Compute number of bytes mod 64 */ 
index = (size_t)((context->count[0] >> 3) & 0x3F); 

/* Update number of bits */ 
if ((context->count[0] += ((UINT4)inputLen << 3)) 
< ((UINT4)inputLen << 3)) 
context->count[1]++; 
context->count[1] += ((UINT4)inputLen >> 29); 

partLen = 64 - index; 

/* Transform as many times as possible. */ 
if (inputLen >= partLen) { 
MD5_memcpy 
((POINTER)&context->buffer[index], (POINTER)input, partLen); 
MD5Transform (context->state, context->buffer); 

for (i = partLen; i + 63 < inputLen; i += 64) 
MD5Transform (context->state, &input); 

index = 0; 
} 
else 
i = 0; 

/* Buffer remaining input */ 
MD5_memcpy 
((POINTER)&context->buffer[index], (POINTER)&input, 
inputLen-i); 
} 




























