#include <node.h>
#include <iostream>
#include "fibonacci.h"

namespace demo
{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Integer;
    using v8::Number;
    using v8::Value;

    void wiki(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        std::cout << "Calling wiki from C++\n";
        std::cout << "Number of arguments: " << args.Length() << "\n";

        const char *fibonacciWiki = R"V0G0N(
             Fibonacci, also known as Leonardo Bonacci, Leonardo of Pisa, or Leonardo Bigollo Pisano, 
             was an Italian mathematician from the Republic of Pisa, 
             considered to be 'the most talented Western mathematician of the Middle Ages'.)V0G0N";

        args.GetReturnValue().Set(String::NewFromUtf8(
                                      isolate, fibonacciWiki)
                                      .ToLocalChecked());
    }

    void sequence(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        std::cout << "Calling sequence from C++\n";
        std::cout << "Number of arguments: " << args.Length() << "\n";

        if (args.Length() >= 1 && args[0]->IsNumber())
        {
            double numberFromJS = args[0].As<Number>()->Value();
            if (numberFromJS >= 0)
            {
                unsigned index = (unsigned)numberFromJS;
                args.GetReturnValue().Set(Integer::NewFromUnsigned(isolate, fibonacciSequence(index)));
            }
            else
            {
                args.GetReturnValue().Set(Undefined(isolate));
            }
        }
        else
        {
            args.GetReturnValue().Set(Undefined(isolate));
        }
    }

    void Initialize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "wiki", wiki);
        NODE_SET_METHOD(exports, "sequence", sequence);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
} // namespace demo