#define NUM 3
int main()
{
    int a;
    vector<int>buf;
    for (int i = 0; i < 4; i++){
        cin >> a;
        buf.push_back(a);
    }
    auto i = find(buf.begin(), buf.end(), NUM);
    while(i != buf.end()){
        cout << *i << " On===Position=== " << (i - buf.begin()) << endl;
        i = find(++i, buf.end(), NUM);
    }
}
