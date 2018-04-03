#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

int main()
{
	const char origin_message[10]="abcdefghi";
	const char key[14]="1234567890123";
	unsigned char coded_message[100];
	unsigned char decoded_message[100];
	long origin_message_length=9;
	long coded_message_length=0;
	long decoded_message_length=0;
	des_code_foralldata((const unsigned char*)origin_message,origin_message_length,(const unsigned char*)key,strlen(key),coded_message,&coded_message_length);//des算法加密
    des_decode_foralldata((const unsigned char*)coded_message,coded_message_length,(const unsigned char*)key,strlen(key),decoded_message,&decoded_message_length);//des算法解密
	des_print((const unsigned char*)origin_message, origin_message_length);
	des_print((const unsigned char*)coded_message, coded_message_length);
	des_print((const unsigned char*)decoded_message, decoded_message_length);
	des_code_forallfile(".\\1234.txt",(const unsigned char*)key,strlen(key),".\\5678.txt");
	des_decode_forallfile(".\\5678.txt",(const unsigned char*)key,strlen(key),".\\9101112.txt");
	system("pause");
	return 0;
}









