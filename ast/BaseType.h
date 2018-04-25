#pragma once

namespace TGC
{
    class BaseType
    {
        public:
            BaseType();
            virtual ~BaseType();
    };
    class ArrayType:public BaseType
    {
        public:
        ArrayType() = default;
        virtual ~ArrayType();
    };

    class BuiltInType:public BaseType
    {
        public:
            BuiltInType() = default;
            virtual ~BuiltInType();
    };

    class IntType:public BuiltInType
    {
        public:
            IntType() = default;
            virtual ~IntType();
    };

    class FloatType:public BuiltInType
    {
        public:
            FloatType() = default;
            virtual ~FloatType();
    };
}