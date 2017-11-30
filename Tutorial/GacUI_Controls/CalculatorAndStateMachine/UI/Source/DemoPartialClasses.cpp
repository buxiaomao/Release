﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "Demo.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, DemoReflection.h) */
#include "DemoReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::Demo::
#define GLOBAL_NAME ::vl_workflow_global::Demo::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::Demo::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_Demo)
	vl_workflow_global::Demo instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_Demo)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	Demo& Demo::Instance()
	{
		return Getvl_workflow_global_Demo().instance;
	}
}

/***********************************************************************
Class (::demo::MainWindowConstructor)
***********************************************************************/

namespace demo
{
	void MainWindowConstructor::__vwsn_initialize_instance_(::demo::MainWindow* __vwsn_this_)
	{
		(this->__vwsn_precompile_0 = __vwsn_this_);
		(this->CalculatorAndStateMachine = ::vl::__vwsn::This(__vwsn_this_)->GetCalculatorAndStateMachine());
		(this->__vwsn_precompile_1 = ::vl::__vwsn::This(this->__vwsn_precompile_0)->GetBoundsComposition());
		{
			::vl::__vwsn::This(this->__vwsn_precompile_1)->SetPreferredMinSize([&](){ ::vl::presentation::Size __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint>(480); __vwsn_temp__.y = static_cast<::vl::vint>(320); return __vwsn_temp__; }());
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetClientSize([&](){ ::vl::presentation::Size __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint>(480); __vwsn_temp__.y = static_cast<::vl::vint>(320); return __vwsn_temp__; }());
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetText(::vl::WString(L"ColorPicker", false));
		}
	}

	MainWindowConstructor::MainWindowConstructor()
	{
	}

/***********************************************************************
Class (::demo::MainWindow)
***********************************************************************/

	::vl::Ptr<::demo::Calculator> MainWindow::GetCalculatorAndStateMachine()
	{
		return this->__vwsn_parameter_CalculatorAndStateMachine;
	}

	MainWindow::MainWindow(::vl::Ptr<::demo::Calculator> __vwsn_ctor_parameter_CalculatorAndStateMachine)
		: ::vl::presentation::controls::GuiWindow(::vl::presentation::theme::ThemeName::Window)
	{
		(this->__vwsn_parameter_CalculatorAndStateMachine = __vwsn_ctor_parameter_CalculatorAndStateMachine);
		auto __vwsn_resource_ = ::vl::__vwsn::This(::vl::presentation::GetResourceManager())->GetResourceFromClassName(::vl::WString(L"demo::MainWindow", false));
		auto __vwsn_resolver_ = ::vl::Ptr<::vl::presentation::GuiResourcePathResolver>(new ::vl::presentation::GuiResourcePathResolver(__vwsn_resource_, ::vl::__vwsn::This(__vwsn_resource_.Obj())->GetWorkingDirectory()));
		::vl::__vwsn::This(this)->SetResourceResolver(__vwsn_resolver_);
		::vl::__vwsn::This(this)->__vwsn_initialize_instance_(this);
	}

	MainWindow::~MainWindow()
	{
		this->FinalizeInstanceRecursively(static_cast<::vl::presentation::controls::GuiControlHost*>(this));
	}

/***********************************************************************
Class (::demo::Calculator)
***********************************************************************/

	::vl::WString Calculator::GetValue()
	{
		return this->__vwsn_prop_Value;
	}
	void Calculator::SetValue(const ::vl::WString& __vwsn_value_)
	{
		if ((this->__vwsn_prop_Value != __vwsn_value_))
		{
			(this->__vwsn_prop_Value = __vwsn_value_);
			::vl::__vwsn::EventInvoke(this->ValueChanged)();
		}
	}

	void Calculator::Update(const ::vl::WString& value)
	{
		this->SetValue(value);
		(this->valueFirst = value);
	}

	void Calculator::Calculate()
	{
		if ((this->valueFirst == ::vl::WString(L"", false)))
		{
			(this->valueFirst = this->GetValue());
		}
		else if ((this->op == ::vl::WString(L"+", false)))
		{
			this->Update(::vl::__vwsn::ToString((::vl::__vwsn::Parse<double>(this->valueFirst) + ::vl::__vwsn::Parse<double>(this->GetValue()))));
		}
		else if ((this->op == ::vl::WString(L"*", false)))
		{
			this->Update(::vl::__vwsn::ToString((::vl::__vwsn::Parse<double>(this->valueFirst) * ::vl::__vwsn::Parse<double>(this->GetValue()))));
		}
		else
		{
			throw ::vl::Exception((::vl::WString(L"Unrecognized operator: ", false) + this->op));
		}
	}

	Calculator::Calculator()
	{
	}

}
#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
