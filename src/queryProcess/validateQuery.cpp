#include <string>
#include<vector>
#include<map>
#include <iostream>
#include "../include/validateQuery.hpp"
#include "../util/util.hpp"
#include "/usr/local/include/hsql/SQLParser.h"
#include "/usr/local/include/hsql/util/sqlhelper.h"
#include "../include/create.hpp"
using namespace std;



int tokenHash(string su)
{
    map<string,int> hash;
    toUpper(su);
    hash.insert({"CREATE",101});
    hash.insert({"INSERT",102});
    hash.insert({"DELETE",103});
    hash.insert({"SELECT",104});
    auto it=hash.find(su);
    return it->second;

}
namespace dbplus {
bool ValidateQuery::isValid(string query, string &err, QType &qType)
{
        err="";
        vector<string> token;
        token=split(query,' ');
        int hash=tokenHash(token[0]);

        /**Parsing the query***/
       hsql::SQLParserResult result;
       hsql::SQLParser::parse(query, &result);
       if (!result.isValid())
       {
            fprintf(stderr, "Given string is not a valid SQL query.\n");
            fprintf(stderr, "%s (L%d:%d)\n",
            result.errorMsg(),
            result.errorLine(),
            result.errorColumn());
            return false;
       }
       return true;
         

        //cout<<hash;
        /*
        switch (hash)
        {
        case 101:
           //Cretae
            qType=WRITE;
            return isCreatevalid(token,err);
            break;
        case 102:
            cout<<"i";
            break;
        case 103:
            cout<<"d";
            break;
        case 104:
            cout<<"s";
            break;
        
        default:
            cout<<"INVALID QUERY"<<endl;
            break;
        }  
        */
        //return false;      
    
}
}
