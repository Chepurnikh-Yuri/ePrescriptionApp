#ifndef WELCOME_PAGE_HPP
#define WELCOME_PAGE_HPP

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>

#include "login_page.hpp"
#include "register_page.hpp"

class WelcomePage : public Wt::WContainerWidget
{
public:
	WelcomePage()
	{
        addStyleClass("welcome-page");

        auto mainLayout = setLayout(std::make_unique<Wt::WVBoxLayout>());

        auto topBar = std::make_unique<Wt::WContainerWidget>();
        auto topLayout = topBar->setLayout(std::make_unique<Wt::WHBoxLayout>());

        auto loginBtn = topLayout->addWidget(
            std::make_unique<Wt::WPushButton>("Login"),
            0,
            Wt::AlignmentFlag::Right
        );

        loginBtn->clicked().connect([=]() {
            auto root = Wt::WApplication::instance()->root();
            root->clear(); 
            root->addWidget(std::make_unique<LoginPage>());
        });

        auto registerBtn = topLayout->addWidget(
            std::make_unique<Wt::WPushButton>("Register"),
            0,
            Wt::AlignmentFlag::Right
        );

        registerBtn->clicked().connect([=]() {
            auto root = Wt::WApplication::instance()->root();
            root->clear();
            root->addWidget(std::make_unique<RegisterPage>());
        });

        topLayout->addStretch(1);

        mainLayout->addWidget(std::move(topBar), 0);

        auto center = std::make_unique<Wt::WContainerWidget>();
        center->addStyleClass("welcome-center");

        auto text = center->addWidget(
            std::make_unique<Wt::WText>("HELLO & WELCOME")
        );
        text->addStyleClass("welcome-text");

        mainLayout->addStretch(1);
        mainLayout->addWidget(std::move(center), 0, Wt::AlignmentFlag::Center);
        mainLayout->addStretch(1);
	}
};

#endif // WELCOME_PAGE_HPP