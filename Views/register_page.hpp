#ifndef REGISTER_PAGE_HPP
#define REGISTER_PAGE_HPP

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <memory>
#include <string>

class RegisterPage : public Wt::WContainerWidget {
public:
    RegisterPage() {
        m_layout = setLayout(std::unique_ptr<Wt::WVBoxLayout>(new Wt::WVBoxLayout()));

        m_nameInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_nameInput->setPlaceholderText("Name");

        m_emailInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_emailInput->setPlaceholderText("Email");

        m_passwordInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_passwordInput->setPlaceholderText("Password");
        m_passwordInput->setEchoMode(Wt::EchoMode::Password);

        m_confirmInput = m_layout->addWidget(std::unique_ptr<Wt::WLineEdit>(new Wt::WLineEdit()));
        m_confirmInput->setPlaceholderText("Set Password");
        m_confirmInput->setEchoMode(Wt::EchoMode::Password);

        Wt::WPushButton* button = m_layout->addWidget(std::unique_ptr<Wt::WPushButton>(new Wt::WPushButton("Registration")));
        button->clicked().connect(this, &RegisterPage::processRegister);

        m_output = m_layout->addWidget(std::unique_ptr<Wt::WText>(new Wt::WText("")));
    }

private:
    Wt::WLineEdit* m_nameInput;
    Wt::WLineEdit* m_emailInput;
    Wt::WLineEdit* m_passwordInput;
    Wt::WLineEdit* m_confirmInput;
    Wt::WText* m_output;
    Wt::WVBoxLayout* m_layout;

    void processRegister() {
        std::string name = m_nameInput->text().toUTF8();
        std::string email = m_emailInput->text().toUTF8();
        std::string password = m_passwordInput->text().toUTF8();
        std::string confirm = m_confirmInput->text().toUTF8();

        if (name.empty() || email.empty() || password.empty() || confirm.empty()) {
            m_output->setText("Please fill in all fields");
            return;
        }

        if (password != confirm) {
            m_output->setText("The passwords do not match.");
            return;
        }

        m_output->setText("Registration successful! Welcome, " + name + "!");
    }
};

#endif // REGISTER_PAGE_HPP
