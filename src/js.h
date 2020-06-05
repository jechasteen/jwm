#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

extern "C" {
#include "duktape.h"
}

static std::vector<std::string> splitString(std::string str, const char c) {
    std::vector<std::string> res;
    std::string s = "";
    for(int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            res.push_back(s);
            std::cout << s;
            s = "";
        } else {
            s += str[i];
        }
    }
    res.push_back(s);
    return res;
}

namespace JS {

class Context {
public:
    Context() { setup(); }
    Context(const char *filename) : m_filename(filename) { setup(); }
    ~Context() { duk_destroy_heap(m_ctx); }

    // Get the contents of a JS global object key
    // keys in the format `root.middle.end`
    std::string getStringFromGlobalObject(std::string keys) {
        std::vector<std::string> vKeys = splitString(keys, '.');
        duk_push_global_object(m_ctx);
        std::for_each(vKeys.cbegin(), vKeys.cend(), [this](std::string key) {
            std::cout << key << std::endl;
            duk_push_string(m_ctx, key.c_str());
            duk_get_prop(m_ctx, -2);
        });
        std::string res = duk_safe_to_string(m_ctx, -1);
        duk_pop_n(m_ctx, vKeys.size() + 1);
        return res;
    }

private:
    duk_context *m_ctx;
    const char *m_filename = "/home/jechasteen/Repos/jwm/src/test.js";

private:
    void setup() {
        m_ctx = duk_create_heap_default();
        if (!m_ctx) {
            std::cout << "Failed to create JS heap.\n";
            throw;
        }
        push_file_as_string(m_ctx, m_filename);
        if (duk_peval(m_ctx) != 0) {
            std::cout << "Error: " << duk_safe_to_string(m_ctx, -1) << std::endl;
            throw;
        }
        duk_pop(m_ctx);
        std::cout << getStringFromGlobalObject("appearance.color") << std::endl;
    }
    void push_file_as_string(duk_context *ctx, const char *filename) {
        FILE *f;
        size_t len;
        char buf[16384];

        f = fopen(filename, "rb");
        if (f) {
            len = fread((void *) buf, 1, sizeof(buf), f);
            fclose(f);
            duk_push_lstring(ctx, (const char *) buf, (duk_size_t) len);
        } else {
            duk_push_undefined(ctx);
        }
    }
};

}