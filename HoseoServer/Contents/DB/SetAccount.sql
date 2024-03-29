﻿SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE InsertAccount
	@name VARCHAR(50),
    @pwd VARCHAR(50)
AS
BEGIN
	-- 격리 레벨 : 완료되지 않은 데이터도 조회 가능
	SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
	--  디버깅 로그 On
	SET NOCOUNT ON;

	BEGIN TRY
		-- 트렌젝션 시작
		BEGIN TRANSACTION TranInsertAccount;

		INSERT INTO TblAccount (name, pwd)
        VALUES (@name, @pwd);

		-- 커밋
		COMMIT TRANSACTION
	END TRY
    BEGIN CATCH

		-- 롤백
		ROLLBACK TRANSACTION
	END CATCH
END
GO
