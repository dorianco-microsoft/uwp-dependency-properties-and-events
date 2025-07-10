using System;
using System.ComponentModel;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace Polarstar
{
    public class ValueChangedEventArgs : EventArgs
    {
        public int NewValue { get; }
        public ValueChangedEventArgs(int newValue)
        {
            NewValue = newValue;
        }
    }

    public delegate void ValueChangedEventHandler(object sender, ValueChangedEventArgs e);

    public sealed partial class MyControl : UserControl, INotifyPropertyChanged
    {
        public static DependencyProperty ValueProperty = DependencyProperty.Register(
            nameof(Value),
            typeof(int),
            typeof(MyControl),
            new PropertyMetadata(default(int)));

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event ValueChangedEventHandler ValueChanged;

        public void OnValueChanged(int newValue)
        {
            ValueChanged?.Invoke(this, new ValueChangedEventArgs(newValue));
        }

        public int Value
        {
            get
            {
                return (int)GetValue(ValueProperty); // inherited method from DependencyObject.GetValue() [see https://learn.microsoft.com/en-us/uwp/api/windows.ui.xaml.dependencyobject.getvalue]
            }
            set
            {        
                if(Value != value) 
                {
                    SetValue(ValueProperty, value); // inherited method from DependencyObject::SetValue() [see https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.dependencyobject.setvalue]
                    OnPropertyChanged(nameof(Value));
                }                
            }
        }

        public MyControl()
        {
            InitializeComponent();
        }

        private void OnButtonClick(object sender, RoutedEventArgs e)
        {
            OnValueChanged(Value + 1);
        }
    }
}
