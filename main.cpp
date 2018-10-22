#include <SFML/Window.hpp>
float L1 = 100.0f;
float L2 = 100.0f;
float T1 = 0.0f;
float T2 = 0.0f;
float M1 = 1.0f;
float M2 = 1.0f;
float A1 = 1.0f;
float A2 = 1.0f;
float V1 = 1.0f;
float V2 = 1.0f;
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;
float A1_acc = 0.0f;
float A2_acc = 0.0f;
float A1_vel = 0.0f;
float A2_vel = 0.0f;
float g = 1.0f;
int main(int argc, char** argv)
{
    sf::Window window(sf::VideoMode(800,600), "My Window");
    
    while(window.isOpen())
    {
        int numerator_1 = -g*(2*M1+M2)*sin(T1);
        int numerator_2 = M2*g*sin(T1-2*T2);
        int numerator_3 = 2*sin(T1-T2)*M2(A2_vel*A2_vel*L2+A1_vel*A1_vel*L1*cos(T1-T2));
        int denumerator_1 = L1*(2*M1+M2-M2*cos(2*T1-2*T2));
        A1_acc = numerator_1 - numerator_2 - numerator_3;
        A1_acc /= denumerator_1;

        numerator_1 = 2*sin(T1-T2);
        numerator_2 = A1_vel*A1_vel*L1(M1+M2);
        numerator_3 = g*(M1+M2)*cos(T1);
        numerator_4 = A2_vel*A2_vel*L2*M2*cos(T1-T2);
        denumerator_1 = L2(2*M1+M2-M2*cos(2*T1-2*T2));
        A2_acc = (numerator_1*(numerator_2+numerator_3+numerator_4));
        A2_acc /= denumerator_1;

        numerator_1 = g*(2*M1+M2)*sin(T1);
        numerator_2 = M2*g*sin(T1-2*T2);
        numerator_4 = A2_vel*A2_vel*L2 + A1_vel*A1_vel*L1*cos(T1-T2);
        numerator_3 = 2*sin(T1-T2)*M2*(numerator_4);
        denumerator_1 = L1*(2*M1+M2-M2*cos(2*T1-2*T2));
        A1_vel = -numerator_1 - numerator_2 - numerator_3;
        A1_vel /= denumerator_1;

        numerator_1 = 2*sin(T1-T2);
        numerator_2 = (A1_vel*A1_vel*L1*(M1+M2));
        numerator_3 = g*(M1+M2)*cos(T1);
        numerator_4 = A2_vel*A2_vel*L2*M2*cos(T1-T2);
        denumerator_1 = L2*(2*M1+M2-M2*cos(2*T1-2*T2));
        A2_vel = numerator_1*(numerator_2+numerator_3+numerator_4);
        A2_vel /= denumerator_1;
        
        T1 += A1_vel;
        T2 += A2_vel;

        x1 = L1 * sin(T1) + 100;
        y1 = -L1 * cos(T1) + 100;
        x2 = x1 + L2 * sin(T2);
        y2 = y1 - L2 * cos(T2);

        sf::CircleShape circle1;
        circle1.setRadius(20);
        circle1.setOutlineColor(sf::Color::Red);
        circle1.setPosition(x1,y1);

        sf::CircleShape circle2;
        circle2.setRadius(20);
        circle2.setOutlineColor(sf::Color::Red);
        circle2.setPosition(x2,y2);
        
        sf::RectangleShape line1(sf::Vector2f(110.f, 5.f));
        line1.setPosition(sf::Vector2f(100,0));
        line1.setRotation(360/(2*pi) * T1);

        sf::RectangleShape line2(sf::Vector2f(110.f,5.f));
        line2.setPosition(sf::Vector2f(x1,x2));
        line2.setRotation(360/(2*pi) * T2);

        window.draw(line1);
        window.draw(circle1);
        window.draw(line2);
        window.draw(circle2);
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
