package Repo;

public class DuplicateEntityException extends Exception{
    public DuplicateEntityException(String message)
    {
        super(message);
    }
}
