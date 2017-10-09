#include <stdio.h>
 #include <openssl/evp.h>
 #include <stdlib.h>
 #include <string.h>

 char hash (char * hashType, char * message)
 {
 EVP_MD_CTX *mdctx;
 const EVP_MD *md;
 unsigned char md_value[EVP_MAX_MD_SIZE]; 
int md_len, i;
 OpenSSL_add_all_digests();
 if(!message) {
 printf("Usage: mdtest digestname\n");
 exit(1);
 }
 md = EVP_get_digestbyname(hashType);
 if(!md) {
 printf("Unknown message digest %s\n", hashType);
 exit(1);
 }
 mdctx = EVP_MD_CTX_create();
 EVP_DigestInit_ex(mdctx, md, NULL);
 EVP_DigestUpdate(mdctx, message, strlen(message));
 EVP_DigestFinal_ex(mdctx, md_value, &md_len);
 EVP_MD_CTX_destroy(mdctx);

// printf("Digest is: ");
 //for(i = 0; i < md_len; i++)
 //printf("%02x", md_value[i]);
 //printf("\n");
 
 return * md_value;
 }

void randomString(char * message){
static const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
static const int numOfLetters = sizeof(alphabet) - 1;
int i;

for(i = 0; i<4; i++)
	message[i] =alphabet[rand()%numOfLetters];
}

int oneWay(char * hashType){
char message[4];
char messageCompare[4];
unsigned char * hashedOne;
unsigned char * hashedTwo;
int count = 0;
int arrayCount = 0;


randomString(message);
hashedOne = hash(hashType,message);

do{
    randomString(messageCompare);
    hashedTwo = hash(hashType,messageCompare);
    count++;
}while(strncmp(&hashedOne,&hashedTwo, 4)!=0); 

return count;
}

int collisionFree (char * hashType){
char message[4];
char messageCompare[4];
unsigned char hashedOne;
unsigned char hashedTwo;
int count = 0;
int arrayCount = 0;

do{
 randomString(message);
 hashedOne = hash(hashType,message);
 randomString(messageCompare);
 hashedTwo = hash(hashType,messageCompare);
 count++;
}while(strncmp(&hashedOne,&hashedTwo,4)!=0);

return count;
}

main(int argc, char *argv[]){
 char * hashType;
 int count; 
 int x;

 if(!argv[1]) {
  printf("Usage: mdtest digestname\n");
  exit(1);
 }
 else{
  hashType = argv[1];
 }

for(x=0; x<=5; x++){
  count += oneWay(hashType); 
  printf("time to crack one-way: %d\n", count);
}
printf("average to crack one-way is %d\n", count/5);

for(x=0; x<=5; x++){ 
  count += collisionFree(hashType);
  printf("time to crack collision-free: %d\n", count);
}
printf("average to crack collision-free is %d\n", count/5);


 /* Call this once before exit. */
 EVP_cleanup();
 exit(0);
}
