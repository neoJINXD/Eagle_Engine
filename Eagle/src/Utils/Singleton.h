#pragma once

namespace Eagle
{
	template<typename T>
	class EAGLE_API Singleton
	{
	public:
		static T& getInstance()
		{
			//static T _instance;
			return *_instance;
		}

	protected:
		Singleton()
		{
			_instance = static_cast<T*>(this);
		}

	private:
		static T* _instance;
	};

}
