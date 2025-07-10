#pragma once
#include "pch.h"
#include "MainPage.xaml.h"

using namespace Pandastar;

void MainPage::OnPropertyChanged(Platform::String^ propertyName)
{
	PropertyChanged(this, ref new Windows::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
}

int MainPage::MyControlValue::get()
{
	return m_MyControlValue;
}

void MainPage::MyControlValue::set(int value)
{
	if (m_MyControlValue != value)
	{
		m_MyControlValue = value;
		OnPropertyChanged("MyControlValue");
	}
}

MainPage::MainPage()
{
	InitializeComponent();
}

void MainPage::OnMyControlValueChanged(Platform::Object^ sender, ValueChangedEventArgs^ e)
{
	MyControlValue = e->NewValue;
}