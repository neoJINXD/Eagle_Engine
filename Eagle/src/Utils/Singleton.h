#pragma once
#if 0
namespace Eagle
{
   template <typename T>
   class EAGLE_API Singleton
   {
    public:
      static T& getInstance()
      {
         // static BANGO _instance = {};
         return *_instance;
      }

    protected:
      Singleton()
      {
         //_instance = static_cast<T*>(this);
         _instance = static_cast<T*>(this);
      }

      ~Singleton() { _instance = nullptr; }

    private:
      static T* _instance;
   };

   template <typename T>
   T* Singleton<T>::_instance = nullptr;
}
#endif
