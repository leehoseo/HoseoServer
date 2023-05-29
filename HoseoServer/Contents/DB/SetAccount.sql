SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE InsertAccount
	@name VARCHAR(50),
    @pwd VARCHAR(50)
AS
BEGIN
	-- �ݸ� ���� : �Ϸ���� ���� �����͵� ��ȸ ����
	SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
	--  ����� �α� On
	SET NOCOUNT ON;

	BEGIN TRY
		-- Ʈ������ ����
		BEGIN TRANSACTION TranInsertAccount;

		INSERT INTO TblAccount (name, pwd)
        VALUES (@name, @pwd);

		-- Ŀ��
		COMMIT TRANSACTION
	END TRY
    BEGIN CATCH

		-- �ѹ�
		ROLLBACK TRANSACTION
	END CATCH
END
GO
