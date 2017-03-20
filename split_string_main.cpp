


#include <iostream>
#include <string.h>
using namespace std;


namespace ASplitString{
char *strdup2(char *str)
{
   if(str== NULL)
	   return NULL;
   int len = strlen(str);
   char *copy = new char[len];
   strcpy(copy, str);
   return copy;
}

int count_occuences(char *str, char ch)
{
    if(str== NULL) return 0;
    int len = 0;
    int iter= 0;
    while(str[iter] != '\0')
    {
    	if(str[iter]== ch)
    		len++;
    	iter++;
    }
    return len;
}

void getSubString(char *result, char *chars, int init , int end)
{
	int length = strlen(chars);
	if((init < length) && (chars != NULL))
	{
		strncpy(result, &chars[init], end - init);
		result[end - init] = '\0';
	}

}

char **splitString(char *str, char token)
{
   char *dup   = strdup2(str);
   char **ret  = NULL;
   int    len  = 0;
   int  ch_cnt = 0;
   int  current_char = 0;
   int  current_str  = 0;
   int  beg = 0;
   if(str!= NULL)
   {
	   len    = strlen(str);
	   ch_cnt = count_occuences(str, token);
       ret    = new char *[ch_cnt];
       for(;;)
       {
    	    if(current_char == len)
                 break;

    	    if(*dup == token)
    	    {
                char* temp = new char[current_char - beg];

                getSubString(temp , str, beg , current_char);
    	    	if(temp == NULL)
    	    	{
    	    		break;
    	    	}

    	    	int current_str_len = strlen(temp);

                ret[current_str] = new char[current_str_len + 1];

                strcpy(ret[current_str], temp);

                cout << ret[current_str]<<endl;
                current_str++;
    	    	beg = current_char+1;
    	        delete temp;
    	        temp = NULL;
    	    }
    	    	current_char++;
                dup++;
       }
   }
   delete dup;
   return ret;
}


char **splitString2(char *str, char token)
{
   char *dup   = strdup2(str);
   char **ret  = NULL;
   int    len  = 0;
   int  ch_cnt = 0;
   int  current_char = 0;
   int  current_str  = 0;
   int  beg = 0;
   if(str!= NULL)
   {
	   len    = strlen(str);
	   ch_cnt = count_occuences(str, token);
       ret    = new char *[ch_cnt + 1 + 1];
       for(;;)
       {
    	    if(current_str == ch_cnt)
    	    {
    	    	break;
    	    }
    	    if(current_char == len)
    	    {
    	    	break;
    	    }
    	    if(*dup == token)
    	    {
                char* temp = new char[current_char - beg];
                getSubString(temp , str, beg , current_char);
    	    	if(temp == NULL)
    	    	{
    	    		break;
    	    	}
    	    	int current_str_len = strlen(temp);
                ret[current_str] = new char[current_str_len + 1];
                strcpy(ret[current_str], temp);
                current_str++;
    	    	beg = current_char+1;
    	        delete temp;
    	        temp = NULL;
    	    }
    	    	current_char++;
                dup++;
       }
       if(current_char < len)
       {
    	   int diference = len - current_char;
    	   ret[current_str+1] = new char[diference + 1];
    	   char *other_temp    = new char[diference + 1];
    	   getSubString(other_temp  , str, current_char, len);
    	   if(other_temp != NULL)
    	   {
    		   strcpy(ret[current_str+1], other_temp  );
    		   if(ret[current_str+1] == NULL)
    		   {

    		   }
    	   }
       }
       else{
    	   ret[ch_cnt + 1]=NULL;
          }
   }
   ret[ch_cnt + 1 + 1] = NULL;
   delete dup;
   return ret;
}

int count_string_quantity_until_null(char **str)
{
   int cnt = 0;
   do{
	   if(str[cnt] == NULL)
		   break;
	   else
		   cnt++;
   }while(1);
   return cnt;

}

void DeleteAllString(char **&str)
{
	   int iter =0;
	   if(str == NULL)return;
	   int c= count_string_quantity_until_null(str);
	   for( ;iter< c; iter++)
	   {
		   if(str[iter] == NULL)break;
		   {
			   cout << "delete String # "<< iter << " is : "<< str[iter]<<endl;
		       delete []str[iter];
		       str[iter] =NULL;
		   }
	   }
	   if(str[iter+1]!= NULL )
	   {
		   cout << "DELETE String # "<< iter +1 << " is : "<< str[iter+1]<<endl;
	       delete []str[iter+1];
	       str[iter] =NULL;
	   }

     delete str;
     str = NULL;
}

bool TestIfNull(char **str){
	return (str==NULL);
}


void PrintAllStr(char **str)
{
   int iter =0;
   if(str == NULL)return;
   int c= count_string_quantity_until_null(str);
   for( ;iter< c; iter++)
   {
	   if(str[iter] == NULL)break;
	     cout << "String # "<< iter << " is : "<< str[iter]<<endl;
   }
   if(str[iter+1]!= NULL )
   {
	   cout << "String # "<< iter +1 << " is : "<< str[iter+1]<<endl;
   }
}
};///end namespace;

int main(int argc, char *argv[])
{
  // char *argv_0 = ASplitString::strdup2(argv[0]);

  // cout << argv_0 <<endl;

  // char *mid= new char[22];
//
 //  ASplitString::getSubString(mid, argv_0, 0, 6);
  // cout << mid <<endl;

  // int o = ASplitString::count_occuences(argv[0], '\\');

//   cout << o;
   cout <<"Argv[0] composed : "<< argv[0]<<endl;
   char **tk1 =  ASplitString::splitString2(argv[0], '\\');
   ASplitString::PrintAllStr(tk1);
   ASplitString::DeleteAllString(tk1);
   cout << boolalpha <<ASplitString::TestIfNull(tk1);


 //  delete argv_0;
 //  argv_0 = NULL;
   return 0;
}
