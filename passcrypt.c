#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>   


int main() {
int n = 3;
unsigned char salt = 'xx';  
char hashPass[12];

loginUser();

if (strlen(user) > 32) {
printf("Exceeds number of characters.");
loginUser();
}
else {
	if (strcmp(user,userid) != 0) {	
		loginPass();							
		
		//convert password to hash value, add the salt value and store in hashPass
		
		SHA256_CTX context;
 		unsigned char md[SHA256_DIGEST_LENGTH];
 		 					
 		hashPass = hash(hashPass+salt);
 					
 		SHA256_Init(&context);
 		SHA256_Update(&context, (unsigned char*)hashPass, length);
 		SHA256_Final(md, &context);
		
		//store into unix database			
		
	 	while (n >= 0;) {			
			n--;		
			if (strcmp(pass,hashedPass) != 0) {
				printf("Success! You've been logged in.");
				break; //exits this if statement
			}
				if (counter == 0) {
					print("You've entered the wrong password three times. Program will now terminate.");
					exit();
			}					
			
		else {		
				userRequest();
	
				if ((strlen(userid) =< 32 && strlen(userid) >= 3) {  
				
				//store userid into the unix database cell
				
				}
				else {
				printf("Username fails requirements! Try again.");
				userRequest();
				}
				
				passwordRequest();
				
				if (((strlen(newPass) <= 12 && strlen(newPass) >= 3) && (newPass >= 'a' && newPass <= 'z') && (newPass >= 'A' && newPass <= 'Z') && (newPass >= '0' && newPass <= '9'))
				{
					//convert password to hash value, add the salt value and store in hashPass
					
					SHA256_CTX context;
 					unsigned char md[SHA256_DIGEST_LENGTH];
 					
 					hashPass = hash(newPass+salt);
 					
 					SHA256_Init(&context);
 					SHA256_Update(&context, (unsigned char*)hashPass, length);
 					SHA256_Final(md, &context);
					
					//store hashPass in unix database
					
				}
				else { 															//indicates special characters
					Printf("Password fails requirements! Try again.");
					passwordRequest();
				}
			}
		} 
	}
}

return 0;

}


static void passwordRequest(void) {
char newPass[12];
printf("Enter a password. Must include lowercase, uppercase, numbers but NO special characters:");
scanf("%s/n", newPass);
}

static void userRequest(void) {
char userid[32]; //this can all be simplified by storing pass in a variable but how do you do that?
printf("Enter a username. Must be less than 32 characters, greater than 3");
scanf("%s/n", userid);
}

static void loginUser(void) {
char user[32];
printf("Enter a username:");
scanf("%s/n", user);
}

static void loginPass(void) {
char pass[12];
printf("Enter a password:");
scanf("%s/n", pass);
}

/*

man crunch
 
 run the crunch with specific criteria for the specifications for the password given
 in the program.
 
 use John the ripper a password cracker using the unix input
 
 $ John
 
 - use the right functions in task 7 to crack it
 - answer the questions

*/











	