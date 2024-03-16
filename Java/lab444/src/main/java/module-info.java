module com.example.lab444 {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics; // trebuia adaugat asta
    requires org.xerial.sqlitejdbc;


    opens com.example.lab444 to javafx.fxml;
    opens com.example.lab444.GUI to javafx.graphics; // si asta
    exports com.example.lab444;
}