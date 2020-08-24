#include <bits/stdc++.h>
using namespace std;

struct Position
{
    int x, y;

    bool operator==(const Position &that) const
    {
        return x == that.x && y == that.y;
    }
};
ostream &operator<<(ostream &os, const Position &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// A chess piece which have capabilities of both king and knight
class King_Knight
{
public:
    //Constructor
    King_Knight(Position current)
    {
        p = current;
    }

    //getter
    Position getPosition() const
    {
        return p;
    }

    //setter

    //Knight moves

    /*
    //King moves
    Position move_King_north() { p = Position{p.x, p.y + 1}; }
    Position move_King_west() { p = Position{p.x - 1, p.y}; }
    Position move_King_south() { p = Position{p.x, p.y - 1}; }
    Position move_King_east() { p = Position{p.x + 1, p.y}; }
*/
private:
    Position p;
};

//King moves
Position move_King_north(Position p)
{
    p = Position{p.x, p.y + 1};
    return p;
}
Position move_King_west(Position p)
{
    p = Position{p.x - 1, p.y};
    return p;
}
Position move_King_south(Position p)
{
    p = Position{p.x, p.y - 1};
    return p;
}
Position move_King_east(Position p)
{
    p = Position{p.x + 1, p.y};
    return p;
}
Position move_King_northeast(Position p)
{
    p = Position{p.x + 1, p.y + 1};
    return p;
}
Position move_King_southeast(Position p)
{
    p = Position{p.x + 1, p.y - 1};
    return p;
}
Position move_King_southwest(Position p)
{
    p = Position{p.x - 1, p.y - 1};
    return p;
}
Position move_King_northwest(Position p)
{
    p = Position{p.x - 1, p.y + 1};
    return p;
}

 //Knight moves
Position move_Knightly_1oClock(Position p)
{
    p = Position{p.x + 1, p.y + 2};
    return p;
}
Position move_Knightly_2oClock(Position p)
{
    p = Position{p.x + 2, p.y + 1};
    return p;
}
Position move_Knightly_4oClock(Position p)
{
    p = Position{p.x + 2, p.y - 1};
    return p;
}
Position move_Knightly_5oClock(Position p)
{
    p = Position{p.x + 1, p.y - 2};
    return p;
}
Position move_Knightly_7oClock(Position p)
{
    p = Position{p.x - 1, p.y - 2};
    return p;
}
Position move_Knightly_8oClock(Position p)
{
    p = Position{p.x - 2, p.y - 1};
    return p;
}
Position move_Knightly_10oClock(Position p)
{
    p = Position{p.x - 1, p.y + 2};
    return p;
}
Position move_Knightly_11oClock(Position p)
{
    p = Position{p.x - 2, p.y + 2};
    return p;
}

double calculateDistance(Position A, Position B)
{
    int Xsquare = (abs(A.x - B.x)) * (abs(A.x - B.x));
    int Ysquare = (abs(A.y - B.y)) * (abs(A.y - B.y));
    return sqrt(Xsquare + Ysquare);
}

int minMovesToDestination(Position current, Position destination, double prev_distance)
{
    if (current == destination)
        return 1;
    double curr_distance = calculateDistance(current, destination);
    cout << current << " " << destination << endl;
    map<double, Position> all_moves = {
        {calculateDistance(move_Knightly_2oClock(current), destination), move_Knightly_2oClock(current)},
        {calculateDistance(move_Knightly_1oClock(current), destination), move_Knightly_1oClock(current)},
        {calculateDistance(move_Knightly_4oClock(current), destination), move_Knightly_4oClock(current)},
        {calculateDistance(move_Knightly_5oClock(current), destination), move_Knightly_5oClock(current)},
        {calculateDistance(move_Knightly_7oClock(current), destination), move_Knightly_7oClock(current)},
        {calculateDistance(move_Knightly_8oClock(current), destination), move_Knightly_8oClock(current)},
        {calculateDistance(move_Knightly_10oClock(current), destination), move_Knightly_10oClock(current)},
        {calculateDistance(move_Knightly_11oClock(current), destination), move_Knightly_11oClock(current)},
        {calculateDistance(move_King_north(current), destination), move_King_north(current)},
        {calculateDistance(move_King_south(current), destination), move_King_south(current)},
        {calculateDistance(move_King_east(current), destination), move_King_east(current)},
        {calculateDistance(move_King_west(current), destination),move_King_west(current)},
        {calculateDistance(move_King_northwest(current), destination), move_King_northwest(current)},
        {calculateDistance(move_King_southwest(current), destination), move_King_southwest(current)},
        {calculateDistance(move_King_northeast(current), destination), move_King_northeast(current)},
        {calculateDistance(move_King_southeast(current), destination), move_King_southeast(current)}};

    return 1 + minMovesToDestination(all_moves.begin()->second, destination, curr_distance);
}

int main(int argc, char const *argv[])
{
    King_Knight kk({4, 4});
    Position destination = {8, 8};
    cout << minMovesToDestination(destination, kk.getPosition(), calculateDistance(kk.getPosition(), destination));
    return 0;
}
