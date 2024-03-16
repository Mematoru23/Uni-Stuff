package entity;

import java.io.Serializable;

public class Song extends AbstractEntity implements Serializable {
    private Integer uniqueID;
    private String band;
    private String title;
    private String genre;
    private int duration;

    public Song() {
    }

    public Song(Integer id, String band, String title, String genre, int duration) {
        this.uniqueID = id;
        this.band = band;
        this.title = title;
        this.genre = genre;
        this.duration = duration;
    }


    public String getBand() {
        return band;
    }

    public void setBand(String band) {
        this.band = band;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    @Override
    public String toString() {
        return "id=" + uniqueID +
                ", band='" + band + '\'' +
                ", title='" + title + '\'' +
                ", genre=" + genre +
                ", duration=" + duration +
                '}';
    }

    @Override
    public void setUniqueID(Integer uniqueID) {
        this.uniqueID = uniqueID;
    }

    @Override
    public Integer getUniqueID() {
        return uniqueID;
    }

}
