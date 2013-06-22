public class Time
{
    public String whatTime(int seconds)
    {
        int mid = seconds % 3600;
        int h = seconds/3600;
        int m = mid/60;
        int s = mid % 60;
        return h + ":" + m + ":" + s;
    }
}
