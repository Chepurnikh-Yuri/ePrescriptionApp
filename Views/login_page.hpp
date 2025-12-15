#ifndef LOGIN_PAGE_HPP
#define LOGIN_PAGE_HPP

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <memory>

class LoginPage : public Wt::WContainerWidget
{
public:
    LoginPage()
    {
        m_layout = setLayout(std::unique_ptr<Wt::WVBoxLayout>(new Wt::WVBoxLayout()));

        m_loginInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_loginInput->setPlaceholderText("email");

        m_passwordInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_passwordInput->setPlaceholderText("password");
        m_passwordInput->setEchoMode(Wt::EchoMode::Password);

        Wt::WPushButton* button = m_layout->addWidget(std::unique_ptr<Wt::WPushButton>(new Wt::WPushButton("Login")));
        button->clicked().connect(this, &LoginPage::processLogin);

        m_output = m_layout->addWidget(std::unique_ptr<Wt::WText>(new Wt::WText("")));
    }

private:
    Wt::WLineEdit* m_loginInput;
    Wt::WLineEdit* m_passwordInput;
    Wt::WText* m_output;
    Wt::WVBoxLayout* m_layout;

    void processLogin() {
        std::string login = m_loginInput->text().toUTF8();
        std::string password = m_passwordInput->text().toUTF8();

        if (login == "admin" && password == "1234")
        {
            m_output->setText("Welcome " + login + "!");
        }
        else
        {
            m_output->setText("Incorrect login or password");
        }
    }
};

#endif // LOGIN_PAGE_HPP
