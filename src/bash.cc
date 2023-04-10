#include <node.h>
#include "bash.h"

namespace bashModule
{
    using v8::FunctionCallbackInfo;
    using v8::Integer;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void runWithResult(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        std::cout << "[RUN WITH RESULT] Calling runWithResult\n";

        if (args.Length() >= 1 && args[0]->IsString())
        {
            v8::String::Utf8Value str(isolate, args[0]);
            std::string cmd(*str);
            std::cout << "[RUN WITH RESULT] Command: " << cmd << "\n";
            std::string result = exec(cmd.c_str());
            args.GetReturnValue().Set(String::NewFromUtf8(
                                          isolate, result.c_str())
                                          .ToLocalChecked());
        }
        else
        {
            args.GetReturnValue().Set(Undefined(isolate));
        }
    }

    void run(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        std::cout << "[RUN] Calling run\n";

        if (args.Length() >= 1 && args[0]->IsString())
        {
            v8::String::Utf8Value str(isolate, args[0]);
            std::string cmd(*str);
            std::cout << "[RUN] Command: " << cmd << "\n";
            exec(cmd.c_str());
        }
    }

    void Initialize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "runWithResult", runWithResult);
        NODE_SET_METHOD(exports, "run", run);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
} // namespace bashModule