#include <iostream>
#include <fstream>

extern "C" {

#include <JavaScriptCore/JavaScript.h>
#include <jsc/jsc.h>

}

namespace JS {

struct Value : public JSCValue {
    Value(JSCValue *val) : m_raw(*val) {}

    JSCValue *raw() const { return &m_raw; }

    std::string toJSON() {
        char *json = jsc_value_to_json(&m_raw, 4);
        std::string json_str = json;
        if (json_str.empty()) {
            return "{}";
        } else {
            return json;
        }
        return "{}";
    }
private:
    JSCValue &m_raw;
};

class Context {
public:
    Context() : m_ctx(jsc_context_new()) {}
    
    Value evalFile(const std::string path) {
        std::ifstream file(path);
        std::string js;
        if (file.is_open()) {
            std::string line;
            while(getline(file, line)) {
                js += line;
            }
        }
        file.close();
        return eval(js);
    }
    Value eval(const std::string js) {
        if (!m_ctx) return Value(jsc_value_new_undefined(m_ctx));
        return Value(jsc_context_evaluate(m_ctx, js.c_str(), js.length()));
    }
    Value global() {
        if (!m_ctx) return Value(jsc_value_new_undefined(m_ctx));
        else return Value(jsc_context_get_global_object(m_ctx));
    }
    Value getValue(const std::string key) {
        if (!m_ctx) return Value(jsc_value_new_undefined(m_ctx));
        else return Value(jsc_context_get_value(m_ctx, key.c_str()));
    }
    void setValue(const std::string key, Value *value) {
        jsc_context_set_value(m_ctx, key.c_str(), value);
    }
    // name: the global varable name, prop: the property to 
    Value getPropertyFromGlobal(std::string name, std::string prop) {
        return Value(jsc_value_object_get_property(getValue(name).raw(), prop.c_str()));
    }

private:
    JSCContext *m_ctx;
};

}