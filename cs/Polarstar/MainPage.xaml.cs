using System.ComponentModel;
using Windows.UI.Xaml.Controls;

namespace Polarstar
{    
    public sealed partial class MainPage : Page, INotifyPropertyChanged
    {
        private int _myControlValue = 5;

        public event PropertyChangedEventHandler PropertyChanged;

        public void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }       
        
        public int MyControlValue 
        {
            get 
            {
                return _myControlValue;
            } 
            set
            {
                if (_myControlValue != value)
                {
                    _myControlValue = value;
                    OnPropertyChanged(nameof(MyControlValue));
                }
            }
        }

        public MainPage()
        {            
            InitializeComponent();
        }

        public void OnMyControlValueChanged(object sender, ValueChangedEventArgs e)
        {
            MyControlValue = e.NewValue;
        }
    }
}
