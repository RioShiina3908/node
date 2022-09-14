#include "export.h"
#include "node.h"
#include "node_options.h"

using node::per_process::native;

extern "C" __declspec(dllexport) void ChibiStart(int argc,
                                                 char* argv[],
                                                 Native* native) {
  node::Start(argc, argv, native);
}

void bindChibi(v8::Local<v8::Context> context, v8::Local<v8::Object> chibi) {
  auto isolate = context->GetIsolate();
  auto run = v8::Function::New(
                 context,
                 [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
                   native->run();
                 },
                 {},
                 0,
                 v8::ConstructorBehavior::kThrow)
                 .ToLocalChecked();
  chibi->Set(context, v8::String::NewFromUtf8Literal(isolate, u8"run"), run)
      .ToChecked();
  if (native->world()) {
    auto world = v8::Object::New(isolate);
    chibi
        ->Set(
            context, v8::String::NewFromUtf8Literal(isolate, u8"world"), world)
        .ToChecked();
    auto setNpcMaxHp =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsBigInt()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcMaxHp(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::BigInt>()->Int64Value());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcMaxHp"),
              setNpcMaxHp)
        .ToChecked();
    auto resetNpcMaxHp =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcMaxHp(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcMaxHp"),
              resetNpcMaxHp)
        .ToChecked();
    auto setNpcLevel =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcLevel(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcLevel"),
              setNpcLevel)
        .ToChecked();
    auto resetNpcLevel =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcLevel(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcLevel"),
              resetNpcLevel)
        .ToChecked();
    auto setNpcWalkSpeed =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcWalkSpeed(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcWalkSpeed"),
              setNpcWalkSpeed)
        .ToChecked();
    auto resetNpcWalkSpeed =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcWalkSpeed(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcWalkSpeed"),
              resetNpcWalkSpeed)
        .ToChecked();
    auto setNpcRunSpeed =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcRunSpeed(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcRunSpeed"),
              setNpcRunSpeed)
        .ToChecked();
    auto resetNpcRunSpeed =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcRunSpeed(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcRunSpeed"),
              resetNpcRunSpeed)
        .ToChecked();
    auto setNpcAtk =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcAtk(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcAtk"),
              setNpcAtk)
        .ToChecked();
    auto resetNpcAtk =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcAtk(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcAtk"),
              resetNpcAtk)
        .ToChecked();
    auto setNpcDef =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcDef(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcDef"),
              setNpcDef)
        .ToChecked();
    auto resetNpcDef =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcDef(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"resetNpcDef"),
              resetNpcDef)
        .ToChecked();
    auto setNpcPhysicalAttack =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcPhysicalAttack(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcPhysicalAttack"),
              setNpcPhysicalAttack)
        .ToChecked();
    auto resetNpcPhysicalAttack =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcPhysicalAttack(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(
            context,
            v8::String::NewFromUtf8Literal(isolate, u8"resetNpcPhysicalAttack"),
            resetNpcPhysicalAttack)
        .ToChecked();
    auto setNpcMagicalAttack =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcMagicalAttack(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcMagicalAttack"),
              setNpcMagicalAttack)
        .ToChecked();
    auto resetNpcMagicalAttack =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcMagicalAttack(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(
            context,
            v8::String::NewFromUtf8Literal(isolate, u8"resetNpcMagicalAttack"),
            resetNpcMagicalAttack)
        .ToChecked();
    auto setNpcPhysicalDefence =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcPhysicalDefence(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(
            context,
            v8::String::NewFromUtf8Literal(isolate, u8"setNpcPhysicalDefence"),
            setNpcPhysicalDefence)
        .ToChecked();
    auto resetNpcPhysicalDefence =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcPhysicalDefence(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate,
                                             u8"resetNpcPhysicalDefence"),
              resetNpcPhysicalDefence)
        .ToChecked();
    auto setNpcMagicalDefence =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcMagicalDefence(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate, u8"setNpcMagicalDefence"),
              setNpcMagicalDefence)
        .ToChecked();
    auto resetNpcMagicalDefence =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcMagicalDefence(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(
            context,
            v8::String::NewFromUtf8Literal(isolate, u8"resetNpcMagicalDefence"),
            resetNpcMagicalDefence)
        .ToChecked();
    auto setNpcIgnorePhysicalDefence =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 3 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber() || !info[2]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->setNpcIgnorePhysicalDefence(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[2].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate,
                                             u8"setNpcIgnorePhysicalDefence"),
              setNpcIgnorePhysicalDefence)
        .ToChecked();
    auto resetNpcIgnorePhysicalDefnece =
        v8::Function::New(
            context,
            [](const v8::FunctionCallbackInfo<v8::Value>& info) -> void {
              if (info.Length() < 2 || !info[0]->IsNumber() ||
                  !info[1]->IsNumber()) {
                return;
              }
              auto context = info.GetIsolate()->GetCurrentContext();
              native->world()->resetNpcIgnorePhysicalDefnece(
                  info[0].As<v8::Number>()->Int32Value(context).ToChecked(),
                  info[1].As<v8::Number>()->Int32Value(context).ToChecked());
            },
            {},
            0,
            v8::ConstructorBehavior::kThrow)
            .ToLocalChecked();
    world
        ->Set(context,
              v8::String::NewFromUtf8Literal(isolate,
                                             u8"resetNpcIgnorePhysicalDefnece"),
              resetNpcIgnorePhysicalDefnece)
        .ToChecked();
  }
}
