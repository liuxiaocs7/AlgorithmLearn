class MyCalendar {

    private TreeMap<Integer, Integer> events;

    public MyCalendar() {
        events = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Map.Entry<Integer, Integer> event = events.floorEntry(start);
        if(event != null && event.getValue() > start) {
            return false;
        }
        event = events.ceilingEntry(start);
        if(event != null && event.getKey() < end) {
            return false;
        }
        events.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */