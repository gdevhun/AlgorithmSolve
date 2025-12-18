#include <string>
#include <vector>

using namespace std;
string s_video_len;
string s_curpos;
string s_op_start;
string s_op_end;

string convertToStr(int num)
{
    string res = "";
    int min = num / 60;
    int sec = num % 60; 
    if (min >= 10) res += to_string(min);
    else
    {
        res += "0";
        res += to_string(min);
    }
    res += ":";
    if (sec >= 10) res += to_string(sec);
    else
    {
        res += "0";
        res += to_string(sec);
    }
    return res;
}
int convertToInt(string &str)
{
    int res = 0;
    res += (str[4] - '0');
    res += (str[3] - '0')*10;
    res += (str[1] - '0')*60;
    res += (str[0] - '0')*600;
    return res;
}
void checkInOpening() {

    if (convertToInt(s_op_start) <= convertToInt(s_curpos) && convertToInt(s_curpos) <= convertToInt(s_op_end)) {
        s_curpos = s_op_end;
    }
}
void commandPrev() {
    checkInOpening();

    int totalsec = convertToInt(s_curpos);
    totalsec -= 10;
    if (totalsec <= 0) { //음수되면
        s_curpos = "00:00";
        return;
    }
    //음수가 안되면
    s_curpos=convertToStr(totalsec);

    checkInOpening();
}
void commandNext() {
    checkInOpening();

    int totalsec = convertToInt(s_curpos);
    totalsec += 10;
    if (totalsec >= convertToInt(s_video_len)) { //동영상최대길이이상시
        s_curpos = s_video_len;
        return;
    }
    //이하일시
    s_curpos = convertToStr(totalsec);

    checkInOpening();
}

void checkInput(string input) {
    if (input == "prev") {
        commandPrev();
    }
    else { //next
        commandNext();
    }
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    s_video_len = video_len;
    s_curpos = pos;
    s_op_start = op_start;
    s_op_end = op_end;

    for (int i = 0; i < commands.size(); i++) {
        checkInput(commands[i]);
    }

    return s_curpos;
}