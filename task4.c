#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>    	//import library
#include <string.h>

//random string input formatting
void setRS(char *messagePointer) {		
	int pos,start=0,end=11;
	for (pos=start;pos<end;pos=pos+1)
    	messagePointer[pos]=rand()%256-128;
}

//runs a random hash (decryption process)

void returnRequiredHash(char * nameOfHash, char *messagePointer, unsigned char *valueOfMD) {
	int lengthOfMD, pos;
	const EVP_MD *pointerOfMD; 	//mxtc provides stack allocation
	EVP_MD_CTX *valMD;	//pointer
	//unsigned char md_value[EVP_MAX_MD_SIZE];	//size of hashed text
	OpenSSL_add_all_digests(); 	//adds all algs to a table; used to initialize functions to a table so if //functions are called they can be looked up in the libraries from the table
	pointerOfMD = EVP_get_digestbyname(nameOfHash);	//must be first initialized using above //code; returns an EVP_MD structure

	if(!pointerOfMD) {
    	printf("Unknown message digest %s\n", nameOfHash);
    	exit(1);
	}
	valMD = EVP_MD_CTX_create(); 	//allocates, intializes and returns a digest context

	// for the three codes below, return 1 = success, return 0 = failure
	EVP_DigestInit_ex(valMD, pointerOfMD, NULL);	//uses a digest to use a digest type from ENGINE
	EVP_DigestUpdate(valMD, messagePointer, strlen(messagePointer)); 	//hashes bytes of data into //digest context ctx can be called multiple times to hash more data
	EVP_DigestFinal_ex(valMD, valueOfMD, &lengthOfMD); 	//returns digest value from ctx, puts into //md; if parameter isn’t NULL then number of bytes is written into the integer

	EVP_MD_CTX_destroy(valMD); //cleans up digest context ctx; called after a digest context isn’t needed
	// shrink the digest's length to 24 (3 words)
	//strncpy( digt, md_value, 3);
}

//cracking algorithm

int crackingCollisionAlgorithm(char * nameOfHash) {
int pos=0;
int x;
int three=3;
int start=0;
int listSize=11;
    	char message[listSize];
    	char message2[listSize];
	unsigned char arr[EVP_MAX_MD_SIZE], arr1[EVP_MAX_MD_SIZE]; 	//allocates and initializes digest con

	//prints the cracked encryption
	// the entire code below runs the cracking, which is the process of looping through the encrypted file
	//the code below prints string to terminal
    
do {
        	//sprintf(msg1, "%d", rand());	// convert to string
    	setRS(message);
    	returnRequiredHash(nameOfHash, message, arr);
        	//sprintf(msg2, "%d", rand());	// convert to string
    	setRS(message2);
    	returnRequiredHash(nameOfHash, message2, arr1);
    	pos++;
	} while (strncmp(arr, arr1, three)!=0);
	//printf("\n cracked after %d tries! %s and %s has same digest ", count, msg1, msg2);
        	printf("Notice:\n");
	printf("After %d tries, it was cracked with same digest!", pos);

	for(x=start;three>x;x=x+1) printf("%02x", arr[x]);
	printf("\n");
	return pos;
}

// the beginning of the process of cracking the  one-way property through looping

int crackingOneWayAlgorithm(char * nameOfHash) {
	int pos=0, x,three=3,listSize=11,start=0,nothing=0;
char message[listSize], message2[listSize];
	unsigned char arr[EVP_MAX_MD_SIZE], arr1[EVP_MAX_MD_SIZE]; 
	// we do not need to generate words, instead generating number only
	setRS(message);
    	//sprintf(msg1, "%d", rand());	// convert to string
	// get an initial message
	returnRequiredHash(nameOfHash, message, arr);
	// run the crack
	do {
        	//sprintf(msg2, "%d", rand());	// convert to string
    	setRS(message2);
    	returnRequiredHash(nameOfHash, message2, arr1);
  else{
    	hash = argv[1];
    	}
	srand((int)(0));	// init random seed
	int x,x2,end=15,start=0,end2=5;
	for (x=start,x2=start;x<end;x=x+1){
    	x2=x2+crackingCollisionAlgorithm(hash);
    	}
        	printf("Notice:\n");
	printf("The average time it took for cracking collision is - %d \n", x2/15);
	for (x=start,x2=start;x<end2;x=x+1)
    	x2=x2+crackingOneWayAlgorithm(hash);
        	printf("Notice:\n");
	printf("The average time it took for cracking one-way is - %d \n", x2/5);
}

//cracking output print stream

    	pos++;
	} while (strncmp(arr, arr1, three)!=nothing);
        	printf("Notice:\n");
	printf("cracked after %d tries! same digest ", pos, message, message2);
	for(x=start;three>x;x=x+1) printf("%02x", arr[x]);
	printf("\n");
	return pos;
}

//begins cracking the collision property through the same process of looping


main(int argc, char *argv[])
{
	char *hash,*itename;
	if(!argv[1]){
    	// set to md5 by default
    	hash = "md5";
    	}
	else{
    	hash = argv[1];
    	}
	srand((int)(0));	// init random seed

 int x,x2,end=15,start=0,end2=5;
	for (x=start,x2=start;x<end;x=x+1){
    	x2=x2+crackingCollisionAlgorithm(hash);
    	}
        	printf("Notice:\n");
	printf("The average time it took for cracking collision is - %d \n", x2/15);
	for (x=start,x2=start;x<end2;x=x+1)
    	x2=x2+crackingOneWayAlgorithm(hash);
        	printf("Notice:\n");
	printf("The average time it took for cracking one-way is - %d \n", x2/5);
}

