package MScCAII;
public class MScCAIIMarks{
    public int SemITotal , SemIITotal;
public MScCAIIMarks(int SemITotal, int SemIITotal){
    this.SemITotal = SemITotal;
    this.SemIITotal = SemIITotal;
}

public int TotalMarks(){
    return SemITotal + SemIITotal;
}

}