#pragma once
#include "pch.h"
#include "MainPage.g.h"
#include "MyControl.xaml.h"

namespace Pandastar
{
	public ref class MainPage sealed : public Windows::UI::Xaml::Data::INotifyPropertyChanged
	{
	private:
		int m_MyControlValue;

	public:
		virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler^ PropertyChanged;

		void OnPropertyChanged(Platform::String^ propertyName);

		property int MyControlValue
		{
			int get();
			void set(int value);
		}

		MainPage();

		void OnMyControlValueChanged(Platform::Object^ sender, ValueChangedEventArgs^ e);
	};
}
