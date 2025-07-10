#pragma once
#include "pch.h"
#include "MyControl.g.h"

namespace Pandastar
{	
	public ref class ValueChangedEventArgs sealed
	{
	private:
		int m_newValue;

	public:
		property int NewValue
		{
			int get();
		}

		ValueChangedEventArgs(int newValue);
	};

	public delegate void ValueChangedEventHandler(Platform::Object^ sender, ValueChangedEventArgs^ e);

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MyControl sealed : public Windows::UI::Xaml::Data::INotifyPropertyChanged
	{
	private:
		static Windows::UI::Xaml::DependencyProperty^ sm_valueProperty;		

	public:
		static property Windows::UI::Xaml::DependencyProperty^ ValueProperty
		{
			Windows::UI::Xaml::DependencyProperty^ get();
		}

		virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler^ PropertyChanged;

		void OnPropertyChanged(Platform::String^ propertyName);
		
		event ValueChangedEventHandler^ ValueChanged;

		void OnValueChanged(int newValue);
		
        property int Value
        {
            int get();
            void set(int value);
        }

		MyControl();

		void OnButtonClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);		
	};
}
