#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
*/

//mine. Not passing some basic tests.

bool Password::has_mixed_case(string phrase){
  bool hasUpper = false;
  bool hasLower = false;

  for (int i = 0; i < phrase.length(); i++){
	  if (isupper(phrase[i])){
		  hasUpper = true;
	  }
	  if (islower(phrase[i])){
		  hasLower = true;
	  }
	  if ((hasUpper == true) && (hasLower == true)){
		  return true;
	  }
  }

  return false;
}


//outside version from git
/*
bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
}
*/


/*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
*/
void Password::set(string pass){
  if(pass.size() >= 8){
	  if(count_leading_characters(pass) <= 3){
		  if(has_mixed_case(pass)){
			  for(int i = 0; i < pass_history.size(); i++){
				  if(pass == pass_history[i]){
					  return; //password in history. return without adding it
				  }
			  }
			  //password was not in history
			  pass_history.push_back(pass);
		  }
	  }
  }
}

/*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
*/
bool Password::authenticate(string pass){
	if(pass_history.size() == 0){
		return false;
	}
	if(pass == pass_history.back()){
		return true;
	}
	return false;
}
