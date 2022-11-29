// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include <sstream>
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Coords;
using namespace Windows::Foundation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppApp::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {


        Coord a(0.0, 0.0);
        auto aStr = a.ToString();
        double bx = 39.0;
        double by = 80.0;
        Coord b(bx, by);
        auto bStr = b.ToString();
        auto aToB = a.Distance(b);
        std::wostringstream wostringstream;

        wostringstream << L"We expect the distance between " << aStr.c_str() << L" and " << bStr.c_str() << L" to be 89.0. We got " << a.Distance(b) << std::endl;

        myButton().Content(box_value(wostringstream.str().c_str()));
    }
}
