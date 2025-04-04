package MScCAI;
public class MScCAIMarks{
    public int SemITotal , SemIITotal;
public MScCAIMarks(int SemITotal, int SemIITotal){
    this.SemITotal = SemITotal;
    this.SemIITotal = SemIITotal;
}

public int TotalMarks(){
    return SemITotal + SemIITotal;
}


}