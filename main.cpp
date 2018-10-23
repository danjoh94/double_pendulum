#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
const double pi = 3.1415926535897;
float L1 = 100.0f;
float L2 = 100.0f;
float T1 = pi/2;
float T2 = pi/2;
float M1 = 1.0f;
float M2 = 1.0f;
double x_1 = 0.0;
double y_1 = 0.0;
double x_2 = 0.0;
double y_2 = 0.0;
double A1_acc = 0.0;
double A2_acc = 0.0;
double A1_vel = 0.0;
double A2_vel = 0.0;
float g = 0.7f;
int WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 800;
int x_0 = WINDOW_WIDTH / 2;
int y_0 = 200;
float radius = 20.0f;

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "My Window");
    window.setFramerateLimit(20);    
    sf::VertexArray lines(sf::LineStrip,0);
    
    while(window.isOpen())
    {
        double numerator_1 = -g*(2*M1+M2)*sin(T1);
        double numerator_2 = M2*g*sin(T1-2*T2);
        double numerator_3 = 2*sin(T1-T2)*M2*(A2_vel*A2_vel*L2+A1_vel*A1_vel*L1*cos(T1-T2));
        double denumerator_1 = L1*(2*M1+M2-M2*cos(2*T1-2*T2));
        A1_acc = numerator_1 - numerator_2 - numerator_3;
        A1_acc /= denumerator_1;

        numerator_1 = 2*sin(T1-T2);
        numerator_2 = A1_vel*A1_vel*L1*(M1+M2);
        numerator_3 = g*(M1+M2)*cos(T1);
        double numerator_4 = A2_vel*A2_vel*L2*M2*cos(T1-T2);
        denumerator_1 = L2*(2*M1+M2-M2*cos(2*T1-2*T2));
        A2_acc = (numerator_1*(numerator_2+numerator_3+numerator_4));
        A2_acc /= denumerator_1;

        A1_vel += A1_acc;
        A2_vel += A2_acc;

        T1 += A1_vel;
        T2 += A2_vel;

        x_1 = L1*sin(T1)+x_0;
        y_1 = L1*cos(T1)+y_0;
        x_2 = x_1+L2*sin(T2);
        y_2 = y_1+L2*cos(T2);

        lines.append(sf::Vertex(sf::Vector2f(x_2+radius,y_2+radius)));
        sf::CircleShape circle1(radius);
        circle1.setPosition(x_1,y_1);

        sf::CircleShape circle2(radius);
        circle2.setPosition(x_2,y_2);
        
        sf::RectangleShape line1(sf::Vector2f(L1+radius, 5.f));
        line1.setPosition(sf::Vector2f(x_0+radius,y_0+radius));
        line1.setRotation(90);
        line1.rotate(360/(2*pi) * -T1);
         
        sf::RectangleShape line2(sf::Vector2f(L2+radius,5.f));
        line2.setPosition(sf::Vector2f(x_1+radius,y_1+radius));
        line2.setRotation(90);
        line2.rotate(360/(2*pi) * -T2);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(lines);
        window.draw(line1);
        window.draw(circle1);
        window.draw(line2);
        window.draw(circle2);
        window.display(); 
    }
    return 0;
}
