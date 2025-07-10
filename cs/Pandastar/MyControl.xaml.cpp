#pragma once
#include "pch.h"
#include "MyControl.xaml.h"

using namespace Pandastar;

int ValueChangedEventArgs::NewValue::get()
{
	return m_newValue;
}

ValueChangedEventArgs::ValueChangedEventArgs(int newValue) : m_newValue(newValue)
{
}

Windows::UI::Xaml::DependencyProperty^ MyControl::sm_valueProperty = Windows::UI::Xaml::DependencyProperty::Register(
	"Value",
	int::typeid,
	MyControl::typeid,
	ref new Windows::UI::Xaml::PropertyMetadata(static_cast<Platform::Object^>(0))
);

Windows::UI::Xaml::DependencyProperty^ MyControl::ValueProperty::get()
{
	return sm_valueProperty;
}

void MyControl::OnPropertyChanged(Platform::String^ propertyName)
{
	PropertyChanged(this, ref new Windows::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
}

void MyControl::OnValueChanged(int newValue)
{
	ValueChanged(this, ref new ValueChangedEventArgs(newValue));
}

int MyControl::Value::get()
{	
	return (int)GetValue(ValueProperty); // inherited method from Platform::DependencyObject::GetValue() [see https://learn.microsoft.com/en-us/uwp/api/windows.ui.xaml.dependencyobject.getvalue]
}

void MyControl::Value::set(int value)
{
	if (Value != value)
	{		
		SetValue(ValueProperty, static_cast<Platform::Object^>(value)); // inherited method from Platform::DependencyObject::SetValue() [see https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.dependencyobject.setvalue]
		OnPropertyChanged("Value");
	}
}

MyControl::MyControl()
{
	InitializeComponent();
}

void MyControl::OnButtonClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	OnValueChanged(Value + 1);
}
