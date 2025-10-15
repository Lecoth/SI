package view;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import model.Conexao;

import java.sql.Connection;
import java.sql.PreparedStatement;

public class CadastroView {

    private Stage stage;

    public CadastroView(Stage stage) {
        this.stage = stage;
    }

    public void mostrarTela() {
        Label titulo = new Label("Cadastro de Usuário");
        titulo.setStyle("-fx-font-size: 18px; -fx-font-weight: bold;");

        Label labelNome = new Label("Nome:");
        TextField campoNome = new TextField();

        Label labelEmail = new Label("Email:");
        TextField campoEmail = new TextField();

        Label labelSenha = new Label("Senha:");
        PasswordField campoSenha = new PasswordField();

        Button botaoCadastrar = new Button("Cadastrar");
        Button botaoVoltar = new Button("Voltar para Login");
        Label mensagem = new Label();

        botaoCadastrar.setOnAction(e -> {
            String nome = campoNome.getText();
            String email = campoEmail.getText();
            String senha = campoSenha.getText();

            if (nome.isEmpty() || email.isEmpty() || senha.isEmpty()) {
                mensagem.setText("⚠️ Preencha todos os campos!");
            } else if (cadastrarUsuario(nome, email, senha)) {
                mensagem.setText("✅ Usuário cadastrado com sucesso!");
                campoNome.clear();
                campoEmail.clear();
                campoSenha.clear();
            } else {
                mensagem.setText("❌ Erro ao cadastrar usuário.");
            }
        });

        // Botão para voltar à tela de login
        botaoVoltar.setOnAction(e -> {
            LoginView login = new LoginView(stage);
            login.mostrarTela();
        });

        VBox layout = new VBox(10, titulo, labelNome, campoNome, labelEmail, campoEmail,
                labelSenha, campoSenha, botaoCadastrar, botaoVoltar, mensagem);
        layout.setAlignment(Pos.CENTER);

        Scene cena = new Scene(layout, 350, 300);
        stage.setScene(cena);
        stage.setTitle("Cadastro");
        stage.show();
    }

    private boolean cadastrarUsuario(String nome, String email, String senha) {
        String sql = "INSERT INTO usuarios (nome, email, senha) VALUES (?, ?, ?)";

        try (Connection conn = Conexao.conectar();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, nome);
            stmt.setString(2, email);
            stmt.setString(3, senha);

            stmt.executeUpdate();
            return true;

        } catch (Exception e) {
            System.out.println("Erro ao cadastrar: " + e.getMessage());
            return false;
        }
    }
}
