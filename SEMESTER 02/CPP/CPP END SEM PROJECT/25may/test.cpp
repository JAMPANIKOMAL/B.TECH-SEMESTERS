#include <vmime/message.hpp>
#include <vmime/vmapi.h>
#include <vmime/components/text.hpp>
#include <iostream>

int main() {
  try {
    // Create a VMime::Message object
    VMime::Message message;

    // Set email headers
    message.setSender(VMime::AddrSpec("Jampani Komal <jampanikomal2005@gmail.com>"));
    message.setRecipient(VMime::AddrSpec("Aashutosh Thakur <thakuraashutosh13.com>"));
    message.setSubject("Your Email Subject");

    // Create plain text message body
    VMime::TextPart* textPart = new VMime::TextPart();
    textPart->setCharset("UTF-8");
    textPart->setText("This is the plain text body of your email.");
    message.addPart(textPart);

    // Configure SMTP connection
    const std::string server = "smtp.example.com";  // Replace with your SMTP server
    const int port = 587;  // Common SMTP port, adjust if needed
    const std::string username = "your_username";
    const std::string password = "your_password";

    vMime::SMTP smtp(server, port);
    smtp.setUserName(username);
    smtp.setPassword(password);
    smtp.setStartTLS(true);  // Enable STARTTLS for secure connections

    // Send the email
    smtp.send(message);
    std::cout << "Email sent successfully!" << std::endl;
  } catch (const VMime::Exception& e) {
    std::cerr << "Error sending email: " << e.what() << std::endl;
  }

  return 0;
}
