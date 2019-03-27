
#include <string>
#include <dlfcn.h>
#include <vector>
#include <assert.h>
#include "op.h"
void* funcs_[256] = { 0 };

#define INDEX(name) name##_index
#define CALL(name, args) ((typeof(name)*)(funcs_[INDEX(name)]))args

/*dynamic generate*/
#define FUNC_SIZE 1
const std::vector<std::string> apis_{
        "add", };
#define add_index 0

#define TEST_BODY               CALL(add,(1,2));

/*dynamic generate*/

/*
bool load(const std::string& so, const std::vector<std::string>& apis)
{
    assert(apis.size() < FUNC_SIZE);
    void* handle = dlopen(so.c_str(), RTLD_LAZY);
    if(!handle)
    {
        printf("ERROR, Message(%s).\n", dlerror());
        return false;
    }

    for (size_t i = 0; i < apis.size(); ++i)
    {
        funcs_[i] = dlsym(handle, apis.at(i).c_str());
        char* szError = dlerror();
        if(szError != NULL)
        {
            printf("ERROR, Message(%s).\n", szError);
            dlclose(handle);
            return false;
        }
    }
    return true;
}

int ma1in()
{
    bool ret = load("so", apis_);
    if (!ret)
        return -1;
    TEST_BODY
    return 0;
}
*/